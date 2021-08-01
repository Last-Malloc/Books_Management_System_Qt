#include "UserInterface.h"
#include "TipWindow.h"
#include "FindPassword.h"
#include <set>
#include <list>

UserInterface::UserInterface(UserItem us, QWidget *parent)
	: User(us), QWidget(parent)
{
	ui.setupUi(this);

	//���ó����ݼ�
	this->setFocusPolicy(Qt::StrongFocus);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	//��Ա������ʼ��
	isMousePressed = false;
	addToListBookFinished = true;
	
	//�б�ؼ�����ί��
	ui.listBook->setItemDelegate(new BookItemDrawer(ui.listBook));
	//�б�ؼ�ȥ�����������
	ui.listBook->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.listLoan->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//--------------------------------------------�źźϲ�--------------------------------------------------	
	//�Զ��尴ť
	connect(ui.btnClose, SIGNAL(clicked()), this, SLOT(OnBtnCloseClicked()));
	connect(ui.btnMin, SIGNAL(clicked()), this, SLOT(OnBtnMinClicked()));
	connect(ui.btnSearch, SIGNAL(clicked()), this, SLOT(OnBtnSearchClicked()));
	connect(ui.btnFreshen, SIGNAL(clicked()), this, SLOT(OnBtnFreShenClicked()));

	connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(OnBtnSearchClicked()));
	connect(ui.listBook, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(OnListBookClicked(QListWidgetItem *)));
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnCurrentIndexChanged(int)));

	connect(ui.cmbAuthor, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbType, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbPublish, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbKuCun, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbDate, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbKuCun, SIGNAL(currentIndexChanged(int)), this, SLOT(OnCmbKuCunIndexChanged(int)));
	connect(ui.cmbDate, SIGNAL(currentIndexChanged(int)), this, SLOT(OnCmbDateIndexChanged(int)));

	//------------------------------��ʼ�����ؼ�-----------------------------
	//ͷ��
	ui.frameHead->headPorName = GBK::ToUnicode(this->ownInfo.iconName);
	ui.frameHead->update();
	//�ʺ���
	ui.label->setText(GBK::ToUnicode("��ã�" + this->ownInfo.name));
	ui.comboBox->setItemText(0, GBK::ToUnicode(this->ownInfo.ID));
	//�б�ؼ���ʾ�����鼮
	AddToListBookItem(FileManage::bookData, true);
	listItemBook = FileManage::bookData;
	ui.cannotFound->hide();
	AddToListLoanItem();
}

UserInterface::~UserInterface()
{
}

void UserInterface::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_F5)
	{
		OnBtnFreShenClicked();
	}
}

void UserInterface::OnBtnFreShenClicked()
{
	FileManage::ReLoadAll();
	ownInfo = *FileManage::SelectUser(ownInfo.ID);
	ReLoadMyLoan();

	//------------------------------��ʼ�����ؼ�-----------------------------
	//ͷ��
	ui.frameHead->headPorName = GBK::ToUnicode(this->ownInfo.iconName);
	ui.frameHead->update();
	//�ʺ���
	ui.label->setText(GBK::ToUnicode("��ã�" + this->ownInfo.name));
	ui.comboBox->setItemText(0, GBK::ToUnicode(this->ownInfo.ID));
	//�б�ؼ���ʾ�����鼮
	AddToListBookItem(FileManage::bookData, true);
	listItemBook = FileManage::bookData;
	AddToListLoanItem();
}

void UserInterface::OnCurrentIndexChanged(int index)
{
	if (index == 1)
	{
		//�ҵ���Ϣ
		WinMyInfo winInfo(ownInfo);
		int result = winInfo.exec();
		if (result == QDialog::Accepted)
		{
			//�����������Ϣ�����������������Ϣ��
			ownInfo = *FileManage::SelectUser(ownInfo.ID);
			ui.frameHead->headPorName = GBK::ToUnicode(ownInfo.iconName);
			ui.frameHead->update();
		}
		ui.comboBox->setCurrentIndex(0);
	} 
	else if (index == 2)
	{
		//�һ�����
		if (ownInfo.scProt == "##")
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��δ�����ܱ������ڹ���Ա���������룡����"));
		}
		else
		{
			FindPassword tempFind;
			//FindPassword����ͨ������AlterUser�������ļ���FileManage�е�����
			tempFind.tUser = &ownInfo;
			tempFind.czFlag = 1;
			tempFind.ui.label_3->hide();
			tempFind.ui.label->setText(GBK::ToUnicode("������"));
			tempFind.ui.label->move(70, 60);
			tempFind.ui.label_2->setText(GBK::ToUnicode("ȷ������"));
			tempFind.ui.label_2->move(40, 120);
			tempFind.ui.lineID->setPlaceholderText(GBK::ToUnicode("������������"));
			tempFind.ui.lineID->move(150, 60);
			tempFind.ui.lineAnswer->setPlaceholderText(GBK::ToUnicode("����������������"));
			tempFind.ui.lineAnswer->move(150, 120);
			tempFind.ui.radioCZ->hide();
			tempFind.ui.radioZH->hide();
			tempFind.ui.btnOK->move(140, 200);
			tempFind.ui.lineID->clear();
			tempFind.ui.lineAnswer->clear();
			tempFind.exec();
		}
		ui.comboBox->setCurrentIndex(0);
	}
	else if (index == 3)
	{
		this->hide();
		emit ZhuxiaoOrExit(1);
	}
	else if (index == 4)
	{
		this->hide();
		emit ZhuxiaoOrExit(2);
	}
}

void UserInterface::OnBtnSearchClicked()
{
	ui.cmbKuCun->setCurrentIndex(0);
	ui.cmbDate->setCurrentIndex(0);
	string key = GBK::FromUnicode(ui.lineEdit->text());
	ui.cannotFound->hide();
	if (key.size() != 0)
	{
		vector<BookItem>tk = SearchBook(key);
		listItemBook = tk;
		if (tk.size() > 0)
		{
			AddToListBookItem(tk, true);
		}
		else
		{
			ui.listBook->clear();
			ui.cannotFound->show();
		}
	} 
	else
	{
		AddToListBookItem(FileManage::bookData, true);
		listItemBook = FileManage::bookData;
	}
}

void UserInterface::AddToListBookItem(vector<BookItem>& tvb, bool flag)
{
	addToListBookFinished = false;

	ui.listBook->clear();

	QListWidgetItem* item;

	set<string>a, t, p;
	if (flag)
	{
		ui.cmbAuthor->clear();
		ui.cmbAuthor->insertItem(0, GBK::ToUnicode("����������"));
		ui.cmbType->clear();
		ui.cmbType->insertItem(0, GBK::ToUnicode("�����Ʒ���"));
		ui.cmbPublish->clear();
		ui.cmbPublish->insertItem(0, GBK::ToUnicode("�����Ƴ�����"));
	}

	for (int i = 0;i< tvb.size();++i)
	{
		item = new QListWidgetItem();
		item->setSizeHint(QSize(ui.listBook->width(), 155));
		item->setData(Qt::DisplayRole, GBK::ToUnicode(tvb[i].ISBN));
		item->setData(Qt::UserRole, GBK::ToUnicode(tvb[i].name));
		item->setData(Qt::UserRole + 1, GBK::ToUnicode(tvb[i].author));
		item->setData(Qt::UserRole + 2, GBK::ToUnicode(tvb[i].category));
		item->setData(Qt::UserRole + 3, GBK::ToUnicode(tvb[i].tableNumber));
		item->setData(Qt::UserRole + 4, GBK::ToUnicode(tvb[i].storageRate));
		item->setData(Qt::UserRole + 5, GBK::ToUnicode(tvb[i].pubCompany));
		item->setData(Qt::UserRole + 6, GBK::ToUnicode(tvb[i].pubDate));
		item->setData(Qt::UserRole + 7, GBK::ToUnicode(tvb[i].image));
		item->setData(Qt::UserRole + 8, GBK::ToUnicode(tvb[i].introduction));
		ui.listBook->addItem(item);

		if (flag)
		{
			if (a.find(tvb[i].author) == a.end())
			{
				a.insert(tvb[i].author);
				ui.cmbAuthor->insertItem((int)a.size(), GBK::ToUnicode(tvb[i].author));
			}
			if (t.find(tvb[i].category) == t.end())
			{
				t.insert(tvb[i].category);
				ui.cmbType->insertItem((int)t.size(), GBK::ToUnicode(tvb[i].category));
			}
			if (p.find(tvb[i].pubCompany) == p.end())
			{
				p.insert(tvb[i].pubCompany);
				ui.cmbPublish->insertItem((int)p.size(), GBK::ToUnicode(tvb[i].pubCompany));
			}
		}
	}

	addToListBookFinished = true;
}

void UserInterface::AddToListLoanItem()
{
	ui.listLoan->clear();

	QListWidgetItem* item;
	int num = myLoan.size();
	for (int i = 0; i < num; ++i)
	{
		item = new QListWidgetItem();
		item->setSizeHint(QSize(1100, 150));
		BookItem *tempBook = FileManage::SelectBook(myLoan[i].ISBN);
		item->setData(Qt::UserRole + 10, GBK::ToUnicode(ownInfo.ID));
		item->setData(Qt::UserRole, GBK::ToUnicode(tempBook->image));
		item->setData(Qt::UserRole + 1, GBK::ToUnicode(tempBook->name)); 
		item->setData(Qt::UserRole + 2, GBK::ToUnicode(myLoan[i].ISBN));
		item->setData(Qt::UserRole + 3, GBK::ToUnicode(myLoan[i].loanDate));
		item->setData(Qt::UserRole + 4, GBK::ToUnicode(myLoan[i].retnDate));
		item->setData(Qt::UserRole + 5, myLoan[i].isRenew);
		ui.listLoan->addItem(item);

		MyLoanItem *w = new MyLoanItem(item, &myLoan[i]);
		ui.listLoan->setItemWidget(item, w);
	}
}

void UserInterface::OnListBookClicked(QListWidgetItem *temp)
{
	temp->setSizeHint(QSize(ui.listBook->width(), 300));
	int row = ui.listBook->currentRow();
	for (int i = 0; i < ui.listBook->count(); ++i)
	{
		if (row != i)
		{
			ui.listBook->item(i)->setSizeHint(QSize(ui.listBook->width(), 155));
		}
	}
}

void UserInterface::BookDeal()
{
	if (addToListBookFinished)
	{
		vector<BookItem>show;
		bool flag1, flag2, flag3, flag;
		for (int i = 0; i < listItemBook.size(); ++i)
		{
			flag1 = flag2 = flag3 = flag = true;
			if (ui.cmbAuthor->currentIndex() != 0 && ui.cmbAuthor->currentText() != GBK::ToUnicode(listItemBook[i].author))
			{
				flag1 = false;
			}
			if (ui.cmbType->currentIndex() != 0 && ui.cmbType->currentText() != GBK::ToUnicode(listItemBook[i].category))
			{
				flag2 = false;
			}
			if (ui.cmbPublish->currentIndex() != 0 && ui.cmbPublish->currentText() != GBK::ToUnicode(listItemBook[i].pubCompany))
			{
				flag3 = false;
			}
			if (!(flag1 && flag2 && flag3))
			{
				flag = false;
			}
			if (flag)
			{
				show.push_back(listItemBook[i]);
			}
		}
		//�������
		if (ui.cmbKuCun->currentIndex() != 0)
		{
			if (ui.cmbKuCun->currentIndex() == 1)
			{
				sort(show.begin(), show.end(), cmpKucunDown);
			}
			else
			{
				sort(show.begin(), show.end(), cmpKucunUp);
			}
		}
		//������������
		if (ui.cmbDate->currentIndex() != 0)
		{
			if (ui.cmbDate->currentIndex() == 1)
			{
				sort(show.begin(), show.end(), cmpDateDown);
			}
			else
			{
				sort(show.begin(), show.end(), cmpDateUp);
			}
		}
		AddToListBookItem(show, false);
	}
}

void UserInterface::OnCmbKuCunIndexChanged(int i)
{
	if (i != 0)
	{
		ui.cmbDate->setCurrentIndex(0);
	}
}

void UserInterface::OnCmbDateIndexChanged(int i)
{
	if (i != 0)
	{
		ui.cmbKuCun->setCurrentIndex(0);
	}
}

//-------------------------------------------�û�����---------------------------------------------------------
//��갴���¼�
void UserInterface::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//�����϶��¼�
void UserInterface::mouseMoveEvent(QMouseEvent *event)
{
	//��������������
	if (isMousePressed == true)
	{

		//����������Ļ��λ��
		QPoint curMousePoint = event->globalPos() - mousePoint;
		//�ƶ�������λ��
		move(curMousePoint);
	}
	event->accept();
}

//����ͷ��¼�
void UserInterface::mouseReleaseEvent(QMouseEvent *event)
{
	//���δ����
	isMousePressed = false;
	event->accept();
}

void UserInterface::OnBtnCloseClicked()
{
	this->close();
}

void UserInterface::OnBtnMinClicked()
{
	this->showMinimized();
}