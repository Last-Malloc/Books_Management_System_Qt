#include "UserInterface.h"
#include "TipWindow.h"
#include "FindPassword.h"
#include <set>
#include <list>

UserInterface::UserInterface(UserItem us, QWidget *parent)
	: User(us), QWidget(parent)
{
	ui.setupUi(this);

	//设置程序快捷键
	this->setFocusPolicy(Qt::StrongFocus);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	//成员变量初始化
	isMousePressed = false;
	addToListBookFinished = true;
	
	//列表控件设置委托
	ui.listBook->setItemDelegate(new BookItemDrawer(ui.listBook));
	//列表控件去除横向滚动条
	ui.listBook->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.listLoan->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//--------------------------------------------信号合槽--------------------------------------------------	
	//自定义按钮
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

	//------------------------------初始化各控件-----------------------------
	//头像
	ui.frameHead->headPorName = GBK::ToUnicode(this->ownInfo.iconName);
	ui.frameHead->update();
	//问候语
	ui.label->setText(GBK::ToUnicode("你好，" + this->ownInfo.name));
	ui.comboBox->setItemText(0, GBK::ToUnicode(this->ownInfo.ID));
	//列表控件显示所有书籍
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

	//------------------------------初始化各控件-----------------------------
	//头像
	ui.frameHead->headPorName = GBK::ToUnicode(this->ownInfo.iconName);
	ui.frameHead->update();
	//问候语
	ui.label->setText(GBK::ToUnicode("你好，" + this->ownInfo.name));
	ui.comboBox->setItemText(0, GBK::ToUnicode(this->ownInfo.ID));
	//列表控件显示所有书籍
	AddToListBookItem(FileManage::bookData, true);
	listItemBook = FileManage::bookData;
	AddToListLoanItem();
}

void UserInterface::OnCurrentIndexChanged(int index)
{
	if (index == 1)
	{
		//我的信息
		WinMyInfo winInfo(ownInfo);
		int result = winInfo.exec();
		if (result == QDialog::Accepted)
		{
			//如果更改了信息，仅重新载入相关信息；
			ownInfo = *FileManage::SelectUser(ownInfo.ID);
			ui.frameHead->headPorName = GBK::ToUnicode(ownInfo.iconName);
			ui.frameHead->update();
		}
		ui.comboBox->setCurrentIndex(0);
	} 
	else if (index == 2)
	{
		//找回密码
		if (ownInfo.scProt == "##")
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("您未设置密保，请于管理员处重置密码！！！"));
		}
		else
		{
			FindPassword tempFind;
			//FindPassword窗口通过调用AlterUser更改了文件和FileManage中的数据
			tempFind.tUser = &ownInfo;
			tempFind.czFlag = 1;
			tempFind.ui.label_3->hide();
			tempFind.ui.label->setText(GBK::ToUnicode("新密码"));
			tempFind.ui.label->move(70, 60);
			tempFind.ui.label_2->setText(GBK::ToUnicode("确认密码"));
			tempFind.ui.label_2->move(40, 120);
			tempFind.ui.lineID->setPlaceholderText(GBK::ToUnicode("请输入新密码"));
			tempFind.ui.lineID->move(150, 60);
			tempFind.ui.lineAnswer->setPlaceholderText(GBK::ToUnicode("请重新输入新密码"));
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
		ui.cmbAuthor->insertItem(0, GBK::ToUnicode("不限制作者"));
		ui.cmbType->clear();
		ui.cmbType->insertItem(0, GBK::ToUnicode("不限制分类"));
		ui.cmbPublish->clear();
		ui.cmbPublish->insertItem(0, GBK::ToUnicode("不限制出版社"));
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
		//库存排序
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
		//出版日期排序
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

//-------------------------------------------用户体验---------------------------------------------------------
//鼠标按下事件
void UserInterface::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//窗体拖动事件
void UserInterface::mouseMoveEvent(QMouseEvent *event)
{
	//若鼠标左键被按下
	if (isMousePressed == true)
	{

		//鼠标相对于屏幕的位置
		QPoint curMousePoint = event->globalPos() - mousePoint;
		//移动主窗体位置
		move(curMousePoint);
	}
	event->accept();
}

//鼠标释放事件
void UserInterface::mouseReleaseEvent(QMouseEvent *event)
{
	//鼠标未按下
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