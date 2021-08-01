#include "MgInterface.h"

//------------------------------------��ҳ��--------------------------------------
MgInterface::MgInterface(UserItem us, QWidget *parent)
	: Manager(us), QWidget(parent)
{
	ui.setupUi(this);

	//���ó����ݼ�
	this->setFocusPolicy(Qt::StrongFocus);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	//���������߹���������Message��ť�ƶ�ˢ�°�ťλ��
	if (ownInfo.power == 1)
	{
		ui.btnMessage->hide();
		ui.btnFreshen->setGeometry(829, 6, 47, 47);
	}

	//��Ա������ʼ��
	isMousePressed = false;
	bookSelectAll = false;
	userSelectAll = false;
	listItemBook = FileManage::bookData;
	listItemUser = FileManage::userData;
	addToListBookFinished = true;
	addToListUserFinished = true;
	ui.cannotFound->hide();
	ui.userCannotFound->hide();
	ui.cannotFoundLeft->hide();
	ui.cannotFoundRight->hide();
	ui.userBarHead->headPorName = GBK::ToUnicode("./headpor/moren.png");
	ui.userBarHead->update();
	ui.bkBarHead->headPorName = GBK::ToUnicode("./bookImage/Ĭ���鼮ͼƬ.png");
	ui.bkBarHead->update();
	ui.sJiaHead->headPorName = GBK::ToUnicode("./bookImage/Ĭ���鼮ͼƬ.png");
	ui.sJiaHead->update();

	//ȥ�����������
	ui.listWidgetOfBook->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.listUser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//--------------------------------------�źźϲ�----------------------------------------------
	//��ҳ��
	connect(ui.btnClose, SIGNAL(clicked()), this, SLOT(OnBtnCloseClicked()));
	connect(ui.btnMin, SIGNAL(clicked()), this, SLOT(OnBtnMinClicked()));
	connect(ui.btnMessage, SIGNAL(clicked()), this, SLOT(OnBtnMessageClicked()));
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnCurrentIndexChanged(int)));
	connect(ui.btnFreshen, SIGNAL(clicked()), this, SLOT(OnBtnFreShenClicked()));

	//ͼ�������޸�/�¼�ҳ��
	connect(ui.btnBookBarHide, SIGNAL(clicked()), this, SLOT(OnBtnBooKBarHideClicked()));
	connect(ui.listWidgetOfBook, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(OnListBookClicked(QListWidgetItem *)));
	connect(ui.bookBarSelect, SIGNAL(clicked()), this, SLOT(OnBtnBkBarSelectClicked()));
	connect(ui.bookBarSearch, SIGNAL(clicked()), this, SLOT(OnBtnSearchClicked()));
	connect(ui.bookBarKey, SIGNAL(returnPressed()), this, SLOT(OnBtnSearchClicked()));
	connect(ui.bkBarDelete, SIGNAL(clicked()), this, SLOT(OnBtnBkBarDeleteClicked()));
	connect(ui.bkBarAlter, SIGNAL(clicked()), this, SLOT(OnBtnBkBarAlterClicked()));
	connect(ui.bkBarChgeHead, SIGNAL(clicked()), this, SLOT(OnBntBkBarChgeHeadClicked()));

	connect(ui.cmbAuthor, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbType, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbPublish, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbKuCun, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbDate, SIGNAL(currentIndexChanged(int)), this, SLOT(BookDeal()));
	connect(ui.cmbKuCun, SIGNAL(currentIndexChanged(int)), this, SLOT(OnCmbKuCunIndexChanged(int)));
	connect(ui.cmbDate, SIGNAL(currentIndexChanged(int)), this, SLOT(OnCmbDateIndexChanged(int)));

	//ͼ�������ϼ�ҳ��
	connect(ui.sJiaChooseFile, SIGNAL(clicked()), this, SLOT(OnBtnSJiaChooseFileClicked()));
	connect(ui.sJiaOK, SIGNAL(clicked()), this, SLOT(OnBtnSJiaOKClicked()));
	connect(ui.sJiaChgeHead, SIGNAL(clicked()), this, SLOT(OnBtnSJiaChgeHeadClicked()));

	//�û��������
	connect(ui.userBarHide, SIGNAL(clicked()), this, SLOT(OnBtnUserBarHideClicked()));
	connect(ui.userBarSearch, SIGNAL(clicked()), this, SLOT(OnBtnUserBarSearchClicked()));
	connect(ui.userBarKey, SIGNAL(returnPressed()), this, SLOT(OnBtnUserBarSearchClicked()));
	connect(ui.listUser, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(OnListUserClicked(QListWidgetItem *)));

	connect(ui.userBarCBInstitute, SIGNAL(currentIndexChanged(int)), this, SLOT(UserDeal()));
	connect(ui.userBarCBClass, SIGNAL(currentIndexChanged(int)), this, SLOT(UserDeal()));
	connect(ui.userBarCBSex, SIGNAL(currentIndexChanged(int)), this, SLOT(UserDeal()));
	connect(ui.userBarCBSort, SIGNAL(currentIndexChanged(int)), this, SLOT(UserDeal()));

	connect(ui.userBarResetPW, SIGNAL(clicked()), this, SLOT(OnBtnUserBarResetPW()));
	connect(ui.userBarSelectAll, SIGNAL(clicked()), this, SLOT(OnBtnUserBarSelectAll()));
	connect(ui.userBarDelete, SIGNAL(clicked()), this, SLOT(OnBtnUserBarDelete()));
	connect(ui.userBarOK, SIGNAL(clicked()), this, SLOT(OnBtnUserBarOKClicked()));

	//���Ĺ������
	connect(ui.jYueOrder, SIGNAL(currentIndexChanged(int)), this, SLOT(OnBtnJYueOrderIndexChanged(int)));
	connect(ui.jYueButton, SIGNAL(clicked()), this, SLOT(OnBtnJYueButtonClicked()));
	connect(ui.jYueLIneID, SIGNAL(returnPressed()), this, SLOT(OnJYueLIneIDReturnPressed()));
	connect(ui.jYueLineISBN, SIGNAL(returnPressed()), this, SLOT(OnJYueLineISBNReturnPressed()));
	connect(ui.listLeft, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(OnListLeftClicked(QListWidgetItem*)));
	connect(ui.listRight, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(OnListRightClicked(QListWidgetItem *)));

	//--------------------------------------------------------------------------------------------
	
	//------------------------------��ʼ�����ؼ�--------------------------------------------------
	//ͷ��
	ui.frameHead->headPorName = GBK::ToUnicode(this->ownInfo.iconName);
	ui.frameHead->update();
	//�ʺ���
	ui.label->setText(GBK::ToUnicode("��ã�" + this->ownInfo.name));
	ui.comboBox->setItemText(0, GBK::ToUnicode(this->ownInfo.ID));
	//--------------------------------------------------------------------------------------------
	AddToListBookItem(FileManage::bookData, true);
	sort(FileManage::userData.begin(), FileManage::userData.end(), cmpIDUp);
	AddToListUserItem(FileManage::userData, true);

	AddToListLeft(FileManage::userData);
	AddToListRight(FileManage::bookData);
	//ΪListLeft����A����ί��
	ui.listLeft->setItemDelegate(new ListLeftOfA(ui.listLeft));
	//ΪlistRight����A����ί��
	ui.listRight->setItemDelegate(new ListRightOfA(ui.listRight));
}

MgInterface::~MgInterface()
{
}

void MgInterface::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_F5)
	{
		OnBtnFreShenClicked();
	}
}

void MgInterface::OnCurrentIndexChanged(int index)
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
		int nn6 = FileManage::recentData.size();

	}
	else if (index == 4)
	{
		this->hide();
		emit ZhuxiaoOrExit(2);
	}
}

void MgInterface::OnBtnMessageClicked()
{
	MessageWindow mw;
	mw.exec();
	listItemUser = FileManage::userData;
	if (ui.jYueOrder->currentIndex() == 0 || ui.jYueOrder->currentIndex() == 2)
	{
		AddToListLeft(FileManage::userData);
	}
	AddToListUserItem(FileManage::userData, true);
	ui.btnMessage->update();
}

void MgInterface::OnBtnFreShenClicked()
{
	//���¼����ļ�����
	FileManage::ReLoadAll();

	ui.btnMessage->update();

	//���¼��ظ�����Ϣ
	ownInfo = *FileManage::SelectUser(ownInfo.ID);

	//��Ա������ʼ��
	bookSelectAll = false;
	userSelectAll = false;
	listItemBook = FileManage::bookData;
	listItemUser = FileManage::userData;
	ui.sJiaHead->headPorName = GBK::ToUnicode("./bookImage/Ĭ���鼮ͼƬ.png");
	ui.sJiaHead->update();

	//ͷ��
	ui.frameHead->headPorName = GBK::ToUnicode(this->ownInfo.iconName);
	ui.frameHead->update();
	//�ʺ���
	ui.label->setText(GBK::ToUnicode("��ã�" + this->ownInfo.name));
	ui.comboBox->setItemText(0, GBK::ToUnicode(this->ownInfo.ID));
	//--------------------------------------------------------------------------------------------
	AddToListBookItem(FileManage::bookData, true);
	sort(FileManage::userData.begin(), FileManage::userData.end(), cmpIDUp);
	AddToListUserItem(FileManage::userData, true);

	AddToListLeft(FileManage::userData);
	AddToListRight(FileManage::bookData);
}

//-----------------------------------���Ĺ������---------------------------------
void MgInterface::OnBtnJYueOrderIndexChanged(int index)
{
	if (index == 0)
	{
		ui.jYueLIneID->show();
		ui.jYueLIneID->setGeometry(170, 20, 360, 50);
		ui.jYueLIneID->clear();

		ui.jYueLineISBN->show();
		ui.jYueLineISBN->setGeometry(570, 20, 360, 50);
		ui.jYueLineISBN->clear();

		ui.jYueButton->setText(GBK::ToUnicode("ȷ��"));

		//ΪListLeft����A����ί��
		ui.listLeft->setItemDelegate(new ListLeftOfA(ui.listLeft));
		//ΪlistRight����A����ί��
		ui.listRight->setItemDelegate(new ListRightOfA(ui.listRight));

		AddToListLeft(FileManage::userData);
		AddToListRight(FileManage::bookData);
	}
	else if (index == 1)
	{
		ui.jYueLIneID->hide();

		ui.jYueLineISBN->show();
		ui.jYueLineISBN->setGeometry(200, 20, 700, 50);
		ui.jYueLineISBN->clear();

		ui.jYueButton->setText(GBK::ToUnicode("ȷ��"));

		//ΪListLeft����B����ί��
		ui.listLeft->setItemDelegate(new ListLeftOfB(ui.listLeft));
		//ΪlistRight����A����ί��
		ui.listRight->setItemDelegate(new ListRightOfA(ui.listRight));

		ui.listLeft->clear();
		AddToListRight(FileManage::bookData);
	}
	else
	{
		ui.jYueLIneID->show();
		ui.jYueLIneID->setGeometry(200, 20, 700, 50);
		ui.jYueLIneID->clear();

		ui.jYueLineISBN->hide();

		ui.jYueButton->setText(GBK::ToUnicode("�˻�"));

		//ΪListLeft����A����ί��
		ui.listLeft->setItemDelegate(new ListLeftOfA(ui.listLeft));
		//ΪlistRight����B����ί��
		ui.listRight->setItemDelegate(new ListRightOfB(ui.listRight));

		AddToListLeft(FileManage::userData);
		ui.listRight->clear();
	}
}

void MgInterface::AddToListLeft(vector<UserItem>vu, string tIsbn)
{
	ui.listLeft->clear();
	QListWidgetItem *item;
	//���Ļ��˻�״̬
	if (ui.jYueOrder->currentIndex() == 0 || ui.jYueOrder->currentIndex() == 2)
	{
		for (int i = 0; i < vu.size(); ++i)
		{
			item = new QListWidgetItem();
			item->setData(Qt::UserRole, GBK::ToUnicode(vu[i].iconName));
			item->setData(Qt::UserRole + 1, GBK::ToUnicode(vu[i].ID));
			item->setData(Qt::UserRole + 2, GBK::ToUnicode(vu[i].name));
			item->setData(Qt::UserRole + 3, GBK::ToUnicode(vu[i].institute));
			item->setData(Qt::UserRole + 4, GBK::ToUnicode(vu[i].className));
			ui.listLeft->addItem(item);
		}
	}
	//��ѯ״̬
	else
	{
		for (int i = 0; i < vu.size(); ++i)
		{
			item = new QListWidgetItem();
			item->setData(Qt::UserRole, GBK::ToUnicode(vu[i].iconName));
			item->setData(Qt::UserRole + 1, GBK::ToUnicode(vu[i].ID));
			item->setData(Qt::UserRole + 2, GBK::ToUnicode(vu[i].name));
			item->setData(Qt::UserRole + 3, GBK::ToUnicode(vu[i].institute));
			item->setData(Qt::UserRole + 4, GBK::ToUnicode(vu[i].className));
			item->setData(Qt::UserRole + 10, GBK::ToUnicode(tIsbn));
			ui.listLeft->addItem(item);
		}
	}
	if (vu.size() == 0)
	{
		ui.cannotFoundLeft->show();
	}
	else
	{
		ui.cannotFoundLeft->hide();
	}
}

void MgInterface::AddToListRight(vector<BookItem>vb, string tId)
{
	ui.listRight->clear();
	QListWidgetItem *item;
	//���Ļ��ѯ״̬
	if (ui.jYueOrder->currentIndex() == 0 || ui.jYueOrder->currentIndex() == 1)
	{
		for (int i = 0; i < vb.size(); ++i)
		{
			item = new QListWidgetItem();
			item->setData(Qt::UserRole, GBK::ToUnicode(vb[i].image));
			item->setData(Qt::UserRole + 1, GBK::ToUnicode(vb[i].ISBN));
			item->setData(Qt::UserRole + 2, GBK::ToUnicode(vb[i].name));
			item->setData(Qt::UserRole + 3, GBK::ToUnicode(vb[i].author));
			item->setData(Qt::UserRole + 4, GBK::ToUnicode(vb[i].pubCompany));
			ui.listRight->addItem(item);
		}
	}
	//��ѯ״̬
	else
	{
		for (int i = 0; i < vb.size(); ++i)
		{
			item = new QListWidgetItem();
			item->setData(Qt::UserRole, GBK::ToUnicode(vb[i].image));
			item->setData(Qt::UserRole + 1, GBK::ToUnicode(vb[i].ISBN));
			item->setData(Qt::UserRole + 2, GBK::ToUnicode(vb[i].name));
			item->setData(Qt::UserRole + 3, GBK::ToUnicode(vb[i].author));
			item->setData(Qt::UserRole + 4, GBK::ToUnicode(vb[i].pubCompany));
			item->setData(Qt::UserRole + 10, GBK::ToUnicode(tId));
			ui.listRight->addItem(item);
		}	
	}
	if (vb.size() == 0)
	{
		ui.cannotFoundRight->show();
	}
	else
	{
		ui.cannotFoundRight->hide();
	}
}

void MgInterface::OnBtnJYueButtonClicked()
{
	string tid, tisbn;
	//����
	if (ui.jYueOrder->currentIndex() == 0)
	{
		if (ui.listLeft->selectedItems().size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��δѡ���κ��û�����ѡ�񣡣���"));
			return;
		}
		if (ui.listRight->selectedItems().size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��δѡ���κ��鼮����ѡ�񣡣���"));
			return;
		}
		tid = GBK::FromUnicode(ui.listLeft->currentItem()->data(Qt::UserRole + 1).toString());
		tisbn = GBK::FromUnicode(ui.listRight->currentItem()->data(Qt::UserRole + 1).toString());
		if (FileManage::SelectLoan(tid, tisbn))
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("���û��ѽ��Ĺ����鼮�������ظ����ģ�����"));
			return;
		}
		LoanItem tAddLoan;
		tAddLoan.ID = tid;
		tAddLoan.ISBN = tisbn;
		tAddLoan.isRenew = 0;
		tAddLoan.loanDate = GetNowTime();
		tAddLoan.retnDate = MyCalculate(tAddLoan.loanDate);
		FileManage::AddLoan(tAddLoan);
		TipWindow::Information_OnlyOK(GBK::ToUnicode("���ĳɹ�������"));
	}
	//��ѯ
	else if (ui.jYueOrder->currentIndex() == 1)
	{
		OnJYueLineISBNReturnPressed();
	}
	//�˻�
	else 
	{
		if (ui.listLeft->selectedItems().size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��δѡ���κ��û�����ѡ�񣡣���"));
			return;
		}
		if (ui.listRight->selectedItems().size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��δѡ���κ��鼮����ѡ�񣡣���"));
			return;
		}
		tid = GBK::FromUnicode(ui.listLeft->currentItem()->data(Qt::UserRole + 1).toString());
		tisbn = GBK::FromUnicode(ui.listRight->currentItem()->data(Qt::UserRole + 1).toString());
		
		delete ui.listRight->currentItem();
		FileManage::DeleteLoan(tid, tisbn);

		TipWindow::Information_OnlyOK(GBK::ToUnicode("�˻��ɹ�������"));
	}
}

void MgInterface::OnJYueLIneIDReturnPressed()
{
	string key = GBK::FromUnicode(ui.jYueLIneID->text());
	if (key.size() != 0)
	{
		vector<UserItem>tk = SearchUser(key);
		AddToListLeft(tk);
	}
	else
	{
		AddToListLeft(FileManage::userData);
	}
}

void MgInterface::OnJYueLineISBNReturnPressed()
{
	string key = GBK::FromUnicode(ui.jYueLineISBN->text());
	if (key.size() != 0)
	{
		vector<BookItem>tk = SearchBook(key);
		AddToListRight(tk);
	}
	else
	{
		AddToListRight(FileManage::bookData);
	}
}

void MgInterface::OnListLeftClicked(QListWidgetItem * tItem)
{
	//���˻�״̬����Ӧ
	if (ui.jYueOrder->currentIndex() == 2)
	{
		string id = GBK::FromUnicode(tItem->data(Qt::UserRole + 1).toString());
		vector<LoanItem>tLoan = SearchLoan(id, true);
		vector<BookItem>tBook;
		for (int i = 0;i < tLoan.size();++i)
		{
			tBook.push_back(*FileManage::SelectBook(tLoan[i].ISBN));
		}
		AddToListRight(tBook, id);
	} 
}

void MgInterface::OnListRightClicked(QListWidgetItem * tItem)
{
	//����ѯ״̬����Ӧ
	if (ui.jYueOrder->currentIndex() == 1)
	{
		string isbn = GBK::FromUnicode(tItem->data(Qt::UserRole + 1).toString());
		vector<LoanItem>tLoan = SearchLoan(isbn, false);
		vector<UserItem>tUser;
		UserItem *t;
		for (int i = 0; i < tLoan.size(); ++i)
		{
				tUser.push_back(*FileManage::SelectUser(tLoan[i].ID));
		}
		AddToListLeft(tUser, isbn);
	}
}

//-----------------------------------ͼ�������޸�/�¼�ҳ��-------------------------
void MgInterface::OnBtnBooKBarHideClicked()
{
	if (ui.MyBookToolBar->isHidden())
	{
		ui.MyBookToolBar->show();
		ui.btnBookBarHide->setArrowType(Qt::DownArrow);
		ui.btnBookBarHide->move(1030, 320);
	} 
	else
	{
		ui.MyBookToolBar->hide();
		ui.btnBookBarHide->setArrowType(Qt::UpArrow);
		ui.btnBookBarHide->move(1030, 633);
	}
}

void MgInterface::AddToListBookItem(vector<BookItem>& tvb, bool flag)
{
	addToListBookFinished = false;

	ui.listWidgetOfBook->clear();

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

	for (int i = 0; i < tvb.size(); ++i)
	{
		item = new QListWidgetItem();
		item->setSizeHint(QSize(ui.listWidgetOfBook->width(), 155));
		item->setData(Qt::UserRole + 9, GBK::ToUnicode(tvb[i].ISBN));
		item->setData(Qt::UserRole, GBK::ToUnicode(tvb[i].name));
		item->setData(Qt::UserRole + 1, GBK::ToUnicode(tvb[i].author));
		item->setData(Qt::UserRole + 2, GBK::ToUnicode(tvb[i].category));
		item->setData(Qt::UserRole + 3, GBK::ToUnicode(tvb[i].tableNumber));
		item->setData(Qt::UserRole + 4, GBK::ToUnicode(tvb[i].storageRate));
		item->setData(Qt::UserRole + 5, GBK::ToUnicode(tvb[i].pubCompany));
		item->setData(Qt::UserRole + 6, GBK::ToUnicode(tvb[i].pubDate));
		item->setData(Qt::UserRole + 7, GBK::ToUnicode(tvb[i].image));
		item->setData(Qt::UserRole + 8, GBK::ToUnicode(tvb[i].introduction));
		ui.listWidgetOfBook->addItem(item);

		ManaBookItem *w = new ManaBookItem(item);
		ui.listWidgetOfBook->setItemWidget(item, w);

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
	bookSelectAll = false;

	addToListBookFinished = true;
}

void MgInterface::BookDeal()
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
		if (show.size() == 0)
		{
			ui.cannotFound->show();
		}
		else
		{
			ui.cannotFound->hide();
		}
		AddToListBookItem(show, false);
	}
}

void MgInterface::OnBtnSearchClicked()
{
	ui.cmbKuCun->setCurrentIndex(0);
	ui.cmbDate->setCurrentIndex(0);
	string key = GBK::FromUnicode(ui.bookBarKey->text());
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
			ui.listWidgetOfBook->clear();
			ui.cannotFound->show();
		}
	}
	else
	{
		AddToListBookItem(FileManage::bookData, true);
		listItemBook = FileManage::bookData;
	}
}

void MgInterface::OnListBookClicked(QListWidgetItem *temp)
{
	ui.bkBarHead->headPorName = temp->data(Qt::UserRole + 7).toString();
	ui.bkBarHead->update();
	ui.bkBarISBN->setText(temp->data(Qt::UserRole + 9).toString());
	ui.bkBarName->setText(temp->data(Qt::UserRole).toString());
	ui.bkBarAuthor->setText(temp->data(Qt::UserRole + 1).toString());
	ui.bookBarcategory->setText(temp->data(Qt::UserRole + 2).toString());
	ui.bkBarTableNumber->setText(temp->data(Qt::UserRole + 3).toString());
	ui.bkBarStorageRate->setText(temp->data(Qt::UserRole + 4).toString());
	ui.bkBarPubCompany->setText(temp->data(Qt::UserRole + 5).toString());
	ui.bkBarPubDate->setText(temp->data(Qt::UserRole + 6).toString());
	ui.bkBarIntroduction->setPlainText(temp->data(Qt::UserRole + 8).toString());
}

void MgInterface::OnCmbKuCunIndexChanged(int i)
{
	if (i != 0)
	{
		ui.cmbDate->setCurrentIndex(0);
	}
}

void MgInterface::OnCmbDateIndexChanged(int i)
{
	if (i != 0)
	{
		ui.cmbKuCun->setCurrentIndex(0);
	}
}

void MgInterface::OnBtnBkBarSelectClicked()
{
	int cnt = ui.listWidgetOfBook->count();
	ManaBookItem *temp;
	if (bookSelectAll)
	{
		bookSelectAll = false;
		for (int i = 0; i < cnt; ++i)
		{
			temp = (ManaBookItem *)(ui.listWidgetOfBook->itemWidget(ui.listWidgetOfBook->item(i)));
			temp->ui.toolButton->setIcon(QIcon(GBK::ToUnicode(":/�û�����С��ť/Resources/С��ť/δѡ��.png")));
			temp->ui.toolButton->setChecked(false);
		}
	}
	else
	{
		bookSelectAll = true;
		for (int i = 0; i < cnt; ++i)
		{
			temp = (ManaBookItem *)(ui.listWidgetOfBook->itemWidget(ui.listWidgetOfBook->item(i)));
			temp->ui.toolButton->setIcon(QIcon(GBK::ToUnicode(":/�û�����С��ť/Resources/С��ť/ѡ��.png")));
			temp->ui.toolButton->setChecked(true);
		}
	}
}

void MgInterface::OnBtnBkBarDeleteClicked()
{
	int resure = TipWindow::Information_OKCancel(GBK::ToUnicode("ȷ���¼�����ѡ���鼮��"));
	if (resure)
	{
		vector<string>ISBNOfDelete;
		int cnt = 0;
		ManaBookItem *temp;

		int cnt_a = ui.listWidgetOfBook->count();

		while (cnt < ui.listWidgetOfBook->count())
		{
			temp = (ManaBookItem *)(ui.listWidgetOfBook->itemWidget(ui.listWidgetOfBook->item(cnt)));
			if (temp != nullptr && temp->ui.toolButton->isChecked())
			{
				ISBNOfDelete.push_back(GBK::FromUnicode(ui.listWidgetOfBook->item(cnt)->data(Qt::UserRole + 9).toString()));
				delete ui.listWidgetOfBook->takeItem(cnt);
			}
			else
			{
				++cnt;
			}
		}
		if (ISBNOfDelete.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��δ��ѡ�κ��鼮������"));
			return;
		}
		FileManage::DeleteBook(ISBNOfDelete);

		listItemBook = FileManage::bookData;
		AddToListLeft(FileManage::userData);
		AddToListRight(FileManage::bookData);
	}
}

void MgInterface::OnBtnBkBarAlterClicked()
{
	int resure = TipWindow::Information_OKCancel(GBK::ToUnicode("ȷ���޸ĵ�ǰ�鼮��"));
	if (resure)
	{
		//--------------------------------��֤��ʽ�Ƿ���ȷ--------------------------------
		//ISBN
		string isbn = GBK::FromUnicode(ui.bkBarISBN->text());
		if (isbn.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("ISBN����Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(isbn, "ISBN"))
		{
			return;
		}

		//��֤ISBN�ĸ�ʽ
		if (!MatchISBN(isbn))
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("ISBN��ʽ����ȷ������"));
			return;
		}

		//��֤ISBN�Ƿ��Ѿ�����
		if (FileManage::SelectBook(isbn) != nullptr && GBK::ToUnicode(isbn) != ui.listWidgetOfBook->currentItem()->data(Qt::UserRole + 9))
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��ISBN�Ѵ��ڣ�����"));
			return;
		}

		//����
		string name = GBK::FromUnicode(ui.bkBarName->text());
		if (name.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��������Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(name, "����"))
		{
			return;
		}

		//����
		string author = GBK::FromUnicode(ui.bkBarAuthor->text());
		if (author.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("���߲���Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(author, "����"))
		{
			return;
		}
		
		//����
		string category = GBK::FromUnicode(ui.bookBarcategory->text());
		if (category.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("���಻��Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(category, "����"))
		{
			return;
		}

		//������
		string pubCompany = GBK::FromUnicode(ui.bkBarPubCompany->text());
		if (pubCompany.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�����粻��Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(pubCompany, "������"))
		{
			return;
		}
		
		//��������
		string pubDate = GBK::FromUnicode(ui.bkBarPubDate->text());
		if (pubDate.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�������ڲ���Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(pubDate, "��������"))
		{
			return;
		}
		//��֤�������ڸ�ʽ
		bool pubDateFlag = true;
		{
			if (!(pubDate.size() == 6 || pubDate.size() == 7))
			{
				pubDateFlag = false;
			}
			if (pubDateFlag)
			{
				for (int iii = 0; iii < pubDate.size(); ++iii)
				{
					if (iii < 4)
					{
						if (pubDate[iii] < '0' || pubDate[iii] > '9')
						{
							pubDateFlag = false;
							break;
						}
					}
					else if (iii == 4)
					{
						if (pubDate[iii] != '.')
						{
							pubDateFlag = false;
							break;
						}
					}
					else
					{
						if (pubDate[iii] < '0' || pubDate[iii] > '9')
						{
							pubDateFlag = false;
							break;
						}
					}
				}
			}
			if (!pubDateFlag)
			{
				TipWindow::Information_OnlyOK(GBK::ToUnicode("���ڸ�ʽ����ȷ������"));
				return;
			}
		}


		//�����
		string tableNumber = GBK::FromUnicode(ui.bkBarTableNumber->text());
		if (tableNumber.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("����Ų���Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(tableNumber, "�����"))
		{
			return;
		}
		
		//�������
		string storageRate = GBK::FromUnicode(ui.bkBarStorageRate->text());
		if (storageRate.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�����������Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(storageRate, "�������"))
		{
			return;
		}
		//��֤���������ʽ
		if (!AllIsDigit(storageRate))
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("���������ʽ����ȷ������"));
			return;
		}
		bool tteemmpp;
		if (GBK::ToUnicode(storageRate).toInt(&tteemmpp) < 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�����������Ϊ��������"));
			return;
		}

		//���
		string introduction = GBK::FromUnicode(ui.bkBarIntroduction->toPlainText());
		if (introduction.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��鲻��Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(introduction, "���"))
		{
			return;
		}
		//-------------------------------------------------------------------------------


		QListWidgetItem *temp = ui.listWidgetOfBook->currentItem();
		bool flag = false;
		if (ui.bkBarHead->headPorName != temp->data(Qt::UserRole + 7).toString()||
			ui.bkBarISBN->text() != temp->data(Qt::UserRole + 9).toString()||
			ui.bkBarName->text() != temp->data(Qt::UserRole).toString()||
			ui.bkBarAuthor->text() != temp->data(Qt::UserRole + 1).toString()||
			ui.bookBarcategory->text() != temp->data(Qt::UserRole + 2).toString()||
			ui.bkBarTableNumber->text() != temp->data(Qt::UserRole + 3).toString()||
			ui.bkBarStorageRate->text() != temp->data(Qt::UserRole + 4).toString()||
			ui.bkBarPubCompany->text() != temp->data(Qt::UserRole + 5).toString()||
			ui.bkBarPubDate->text() != temp->data(Qt::UserRole + 6).toString()||
			ui.bkBarIntroduction->toPlainText() != temp->data(Qt::UserRole + 8).toString())
		{
			flag = true;
		}
		
		//�û��޸�������
		if (flag)
		{
			//����Ϊ�������޸�
			//�޸�ListWidget�е�����
			ManaBookItem *tempWidget = (ManaBookItem *)(ui.listWidgetOfBook->itemWidget(temp));
			tempWidget->ui.frameHead->headPorName = ui.bkBarHead->headPorName;
			tempWidget->ui.frameHead->update();
			tempWidget->ui.ISBN->setText(ui.bkBarISBN->text());
			tempWidget->ui.name->setText(ui.bkBarName->text());
			tempWidget->ui.author->setText(ui.bkBarAuthor->text());
			tempWidget->ui.category->setText(GBK::ToUnicode("����:") + ui.bookBarcategory->text());
			tempWidget->ui.tableNumber->setText(GBK::ToUnicode("�����:") + ui.bkBarTableNumber->text());
			tempWidget->ui.storageRate->setText(GBK::ToUnicode("���:") + ui.bkBarStorageRate->text());
			tempWidget->ui.pubCompany->setText(ui.bkBarPubCompany->text());
			tempWidget->ui.pubDate->setText(ui.bkBarPubDate->text());
			tempWidget->ui.introduction->setText(ui.bkBarIntroduction->toPlainText());

			//�޸�bookData�е�����
			BookItem *tBokItem = FileManage::SelectBook(GBK::FromUnicode(temp->data(Qt::UserRole + 9).toString()));
			tBokItem->image = GBK::FromUnicode(ui.bkBarHead->headPorName);
			tBokItem->ISBN = GBK::FromUnicode(ui.bkBarISBN->text());
			tBokItem->name = GBK::FromUnicode(ui.bkBarName->text());
			tBokItem->author = GBK::FromUnicode(ui.bkBarAuthor->text());
			tBokItem->category = GBK::FromUnicode(ui.bookBarcategory->text());
			tBokItem->tableNumber = GBK::FromUnicode(ui.bkBarTableNumber->text());
			tBokItem->storageRate = GBK::FromUnicode(ui.bkBarStorageRate->text());
			tBokItem->pubCompany = GBK::FromUnicode(ui.bkBarPubCompany->text());
			tBokItem->pubDate = GBK::FromUnicode(ui.bkBarPubDate->text());
			tBokItem->introduction = GBK::FromUnicode(ui.bkBarIntroduction->toPlainText());
			
			listItemBook = FileManage::bookData;

			//�޸��ļ��е�����
			FileManage::WriteToBook_Txt();
		} 
		else//�û�δ�޸�����
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��δ�޸��κ�����ֵ������"));
			return;
		}
	}
}

void MgInterface::OnBntBkBarChgeHeadClicked()
{
	QString t = ui.bkBarHead->headPorName;
	ui.bkBarHead->headPorName = QFileDialog::getOpenFileName(this, GBK::ToUnicode("ѡ���鼮ͼƬ"), GBK::ToUnicode("*.jpg;;*.png"));
	if (ui.bkBarHead->headPorName.isEmpty())
	{
		ui.bkBarHead->headPorName = t;
	}
	ui.bkBarHead->update();
}

//-----------------------------------ͼ�������ϼ�ҳ��--------------------------------------

void MgInterface::OnBtnSJiaChooseFileClicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, GBK::ToUnicode("ѡ���鼮�����ļ�"), GBK::ToUnicode("*.txt"));
	if (fileName.isEmpty())
	{
		ui.sJiaFilepath->setText(GBK::ToUnicode("δѡ����Ч�ļ�!!!"));
	}
	else
	{
		ui.sJiaFilepath->setText(fileName);

		ifstream myCin(GBK::FromUnicode(fileName));
		int num;
		myCin >> num;
		BookItem t;
		for (int i = 0; i < num; ++i)
		{
			myCin >> t.ISBN >> t.name >> t.author >> t.category >> t.tableNumber
				>> t.storageRate >> t.pubCompany >> t.pubDate >> t.image >> t.introduction;
			FileManage::bookData.push_back(t);
		}
		myCin.close();
		listItemBook = FileManage::bookData;
		FileManage::WriteToBook_Txt();
		TipWindow::Information_OnlyOK(GBK::ToUnicode("��������ɹ�������"));
	}
}

void MgInterface::OnBtnSJiaOKClicked()
{
	//--------------------------------��֤��ʽ�Ƿ���ȷ--------------------------------
	//ͷ����
	string headPorName = GBK::FromUnicode(ui.sJiaHead->headPorName);
	//ISBN
	string isbn = GBK::FromUnicode(ui.sJiaISBN->text());
	if (isbn.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("ISBN����Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(isbn, "ISBN"))
	{
		return;
	}
	
	//��֤ISBN�ĸ�ʽ
	if (!MatchISBN(isbn))
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("ISBN��ʽ����ȷ������"));
		return;
	}
	
	//��֤ISBN�Ƿ��Ѿ�����
	if (FileManage::SelectBook(isbn))
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("��ISBN�Ѵ��ڣ�����"));
		return;
	}

	//����
	string name = GBK::FromUnicode(ui.sJiaName->text());
	if (name.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("��������Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(name, "����"))
	{
		return;
	}
	//����
	string author = GBK::FromUnicode(ui.sJiaAuthor->text());
	if (author.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("���߲���Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(author, "����"))
	{
		return;
	}
	//����
	string category = GBK::FromUnicode(ui.sJiaCategory->text());
	if (category.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("���಻��Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(category, "����"))
	{
		return;
	}

	//������
	string pubCompany = GBK::FromUnicode(ui.sJiaPubCompany->text());
	if (pubCompany.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("�����粻��Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(pubCompany, "������"))
	{
		return;
	}
	//��������
	string pubDate = GBK::FromUnicode(ui.sJiaPubDate->text());
	if (pubDate.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("�������ڲ���Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(pubDate, "��������"))
	{
		return;
	}
	//��֤�������ڸ�ʽ
	bool pubDateFlag = true;
	{
		if (!(pubDate.size() == 6 || pubDate.size() == 7))
		{
			pubDateFlag = false;
		}
		if (pubDateFlag)
		{
			for (int iii = 0;iii < pubDate.size();++iii)
			{
				if (iii < 4)
				{
					if (pubDate[iii] < '0' || pubDate[iii] > '9')
					{
						pubDateFlag = false;
						break;
					}
				} 
				else if (iii == 4)
				{
					if (pubDate[iii] != '.')
					{
						pubDateFlag = false;
						break;
					}
				}
				else
				{
					if (pubDate[iii] < '0' || pubDate[iii] > '9')
					{
						pubDateFlag = false;
						break;
					}
				}
			}
		}
		if (!pubDateFlag)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("���ڸ�ʽ����ȷ������"));
			return;
		}
	}
	

	//�����
	string tableNumber = GBK::FromUnicode(ui.sJiaTableNumber->text());
	if (tableNumber.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("����Ų���Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(tableNumber, "�����"))
	{
		return;
	}
	//�������
	string storageRate = GBK::FromUnicode(ui.sJiaStorageRate->text());
	if (storageRate.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("�����������Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(storageRate, "�������"))
	{
		return;
	}
	//��֤���������ʽ
	if (!AllIsDigit(storageRate))
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("���������ʽ����ȷ������"));
		return;
	}
	bool tteemmpp;
	if (GBK::ToUnicode(storageRate).toInt(&tteemmpp) < 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("�����������Ϊ��������"));
		return;
	}

	//���
	string introduction = GBK::FromUnicode(ui.sJiaIntroduction->toPlainText());
	if (introduction.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("��鲻��Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(introduction, "���"))
	{
		return;
	}
	//-------------------------------------------------------------------------------

	BookItem bt;
	bt.image = headPorName;
	bt.ISBN = isbn;
	bt.name = name;
	bt.author = author;
	bt.category = category;
	bt.pubCompany = pubCompany;
	bt.pubDate = pubDate;
	bt.tableNumber = tableNumber;
	bt.storageRate = storageRate;
	bt.introduction = introduction;
	FileManage::bookData.push_back(bt);
	listItemBook = FileManage::bookData;
	FileManage::WriteToBook_Txt();

	TipWindow::Information_OnlyOK(GBK::ToUnicode("�鼮��ӳɹ�!!!"));
	
	//���пؼ��ص���ʼ״̬
	ui.sJiaHead->headPorName = GBK::ToUnicode("./bookImage/Ĭ���鼮ͼƬ.png");
	ui.sJiaHead->update();
	ui.sJiaISBN->clear();
	ui.sJiaName->clear();
	ui.sJiaAuthor->clear();
	ui.sJiaCategory->clear();
	ui.sJiaPubCompany->clear();
	ui.sJiaPubDate->clear();
	ui.sJiaTableNumber->clear();
	ui.sJiaStorageRate->clear();
	ui.sJiaIntroduction->clear();
}

void MgInterface::OnBtnSJiaChgeHeadClicked()
{
	QString t = ui.sJiaHead->headPorName;
	ui.sJiaHead->headPorName = QFileDialog::getOpenFileName(this, GBK::ToUnicode("ѡ���鼮ͼƬ"), GBK::ToUnicode("*.jpg;;*.png"));
	if (ui.bkBarHead->headPorName.isEmpty())
	{
		ui.sJiaHead->headPorName = t;
	}
	ui.sJiaHead->update();
}

//-----------------------------------�û�����ҳ��----------------------------------------------
void MgInterface::OnBtnUserBarHideClicked()
{
	if (ui.userBar->isHidden())
	{
		ui.userBar->show();
		ui.userBarHide->setArrowType(Qt::DownArrow);
		ui.userBarHide->move(1030, 380);
	}
	else
	{
		ui.userBar->hide();
		ui.userBarHide->setArrowType(Qt::UpArrow);
		ui.userBarHide->move(1030, 680);
	}
}

void MgInterface::OnBtnUserBarSearchClicked()
{
	ui.userBarCBSort->setCurrentIndex(0);
	ui.userBarCBSex->setCurrentIndex(0);

	string key = GBK::FromUnicode(ui.userBarKey->text());

	ui.userCannotFound->hide();

	if (key.size() != 0)
	{
		vector<UserItem>tk = SearchUser(key);
		listItemUser = tk;
		if (tk.size() > 0)
		{
			AddToListUserItem(tk, true);
		}
		else
		{
			ui.listUser->clear();
			ui.userCannotFound->show();
		}
	}
	else
	{
		AddToListUserItem(FileManage::userData, true);
		listItemUser = FileManage::userData;
	}
}

void MgInterface::OnListUserClicked(QListWidgetItem * temp)
{
	ui.userBarHead->headPorName = temp->data(Qt::UserRole).toString();
	ui.userBarHead->update();
	ui.userBarID->setText(temp->data(Qt::UserRole + 1).toString());
	if (temp->data(Qt::UserRole + 2).toString() == GBK::ToUnicode("1"))
	{
		ui.userBarSex->setText(GBK::ToUnicode("����Ա"));
	} 
	else
	{
		ui.userBarPower->setText(GBK::ToUnicode("��ͨ�û�"));
	}
	ui.userBarName->setText(temp->data(Qt::UserRole + 3).toString());
	if (temp->data(Qt::UserRole + 4).toString() == GBK::ToUnicode("1"))
	{
		ui.userBarSex->setText(GBK::ToUnicode("��"));
	}
	else
	{
		ui.userBarSex->setText(GBK::ToUnicode("Ů"));
	}
	ui.userBarInstitute->setText(temp->data(Qt::UserRole + 5).toString());
	ui.userBarClass->setText(temp->data(Qt::UserRole + 6).toString());
}

void MgInterface::AddToListUserItem(vector<UserItem>& tvb, bool flag)
{
	addToListUserFinished = false;

	ui.listUser->clear();

	QListWidgetItem* item;

	set<string>in, cl;
	if (flag)
	{
		ui.userBarCBInstitute->clear();
		ui.userBarCBInstitute->insertItem(0, GBK::ToUnicode("����ѧԺ"));
		ui.userBarCBClass->clear();
		ui.userBarCBClass->insertItem(0, GBK::ToUnicode("���ް༶"));
	}

	//�жϵ�ǰ�˻��Ƿ�Ϊ��߹���Ա
	bool currIsRoot;
	if (ownInfo.power == 2)
	{
		currIsRoot = true;
	} 
	else
	{
		currIsRoot = false;
	}

	if (currIsRoot)
	{
		for (int i = 0; i < tvb.size(); ++i)
		{
			if (tvb[i].ID != ownInfo.ID)
			{
				item = new QListWidgetItem();
				item->setSizeHint(QSize(ui.listWidgetOfBook->width(), 120));
				item->setData(Qt::UserRole, GBK::ToUnicode(tvb[i].iconName));
				item->setData(Qt::UserRole + 1, GBK::ToUnicode(tvb[i].ID));
				item->setData(Qt::UserRole + 2, tvb[i].power);
				item->setData(Qt::UserRole + 3, GBK::ToUnicode(tvb[i].name));
				item->setData(Qt::UserRole + 4, tvb[i].sex);
				item->setData(Qt::UserRole + 5, GBK::ToUnicode(tvb[i].institute));
				item->setData(Qt::UserRole + 6, GBK::ToUnicode(tvb[i].className));
				ui.listUser->addItem(item);

				ManaUserItem *w = new ManaUserItem(item);
				ui.listUser->setItemWidget(item, w);

				if (flag)
				{
					if (in.find(tvb[i].institute) == in.end())
					{
						in.insert(tvb[i].institute);
						ui.userBarCBInstitute->insertItem((int)in.size(), GBK::ToUnicode(tvb[i].institute));
					}
					if (cl.find(tvb[i].className) == cl.end())
					{
						cl.insert(tvb[i].className);
						ui.userBarCBClass->insertItem((int)cl.size(), GBK::ToUnicode(tvb[i].className));
					}
				}
			}
		}
	} 
	else
	{
		for (int i = 0; i < tvb.size(); ++i)
		{
			if (tvb[i].ID != ownInfo.ID && tvb[i].power != 1)
			{
				item = new QListWidgetItem();
				item->setSizeHint(QSize(ui.listWidgetOfBook->width(), 120));
				item->setData(Qt::UserRole, GBK::ToUnicode(tvb[i].iconName));
				item->setData(Qt::UserRole + 1, GBK::ToUnicode(tvb[i].ID));
				item->setData(Qt::UserRole + 2, tvb[i].power);
				item->setData(Qt::UserRole + 3, GBK::ToUnicode(tvb[i].name));
				item->setData(Qt::UserRole + 4, tvb[i].sex);
				item->setData(Qt::UserRole + 5, GBK::ToUnicode(tvb[i].institute));
				item->setData(Qt::UserRole + 6, GBK::ToUnicode(tvb[i].className));
				ui.listUser->addItem(item);

				ManaUserItem *w = new ManaUserItem(item);
				ui.listUser->setItemWidget(item, w);

				if (flag)
				{
					if (in.find(tvb[i].institute) == in.end())
					{
						in.insert(tvb[i].institute);
						ui.userBarCBInstitute->insertItem((int)in.size(), GBK::ToUnicode(tvb[i].institute));
					}
					if (cl.find(tvb[i].className) == cl.end())
					{
						cl.insert(tvb[i].className);
						ui.userBarCBClass->insertItem((int)cl.size(), GBK::ToUnicode(tvb[i].className));
					}
				}
			}
		}
	}
	
	userSelectAll = false;

	addToListUserFinished = true;
}

void MgInterface::UserDeal()
{
	if (addToListUserFinished)
	{
		vector<UserItem>show;
		bool flag1, flag2, flag3, flag;
		for (int i = 0; i < listItemUser.size(); ++i)
		{
			flag1 = flag2 = flag3 = flag = true;
			if (ui.userBarCBInstitute->currentIndex() != 0 && ui.userBarCBInstitute->currentText() != GBK::ToUnicode(listItemUser[i].institute))
			{
				flag1 = false;
			}
			if (ui.userBarCBClass->currentIndex() != 0 && ui.userBarCBClass->currentText() != GBK::ToUnicode(listItemUser[i].className))
			{
				flag2 = false;
			}
			if (ui.userBarCBSex->currentIndex() != 0)
			{
				if ((ui.userBarCBSex->currentIndex() == 1 && listItemUser[i].sex != 1) || (ui.userBarCBSex->currentIndex() == 2 && listItemUser[i].sex != 0))
				{
					flag3 = false;
				}
			}
			if (!(flag1 && flag2 && flag3))
			{
				flag = false;
			}
			if (flag)
			{
				show.push_back(listItemUser[i]);
			}
		}
		//������AddToListUserItem��
		if (ui.userBarCBSort->currentIndex() == 0)
		{
			sort(show.begin(), show.end(), cmpIDUp);
		}
		else
		{
			sort(show.begin(), show.end(), cmpIDDown);
		}
		if (show.size() == 0)
		{
			ui.userCannotFound->show();
		}
		else
		{
			ui.userCannotFound->hide();
		}
		AddToListUserItem(show, false);
	}
}

void MgInterface::OnBtnUserBarResetPW()
{
	int resure = TipWindow::Information_OKCancel(GBK::ToUnicode("ȷ�����ø��û������룿"));
	if (resure)
	{
		UserItem *t = FileManage::SelectUser(GBK::FromUnicode(ui.listUser->currentItem()->data(Qt::UserRole + 1).toString()));
		t->password = "111111";
		listItemUser = FileManage::userData;
		FileManage::WriteToUser_Txt();
		TipWindow::Information_OnlyOK(GBK::ToUnicode("�����ø��û�������Ϊ111111"));
	}
}

void MgInterface::OnBtnUserBarSelectAll()
{
	int cnt = ui.listUser->count();
	ManaUserItem *temp;
	if (userSelectAll)
	{
		userSelectAll = false;
		for (int i = 0; i < cnt; ++i)
		{
			temp = (ManaUserItem *)(ui.listUser->itemWidget(ui.listUser->item(i)));
			temp->ui.toolButton->setIcon(QIcon(GBK::ToUnicode(":/�û�����С��ť/Resources/С��ť/δѡ��.png")));
			temp->ui.toolButton->setChecked(false);
		}
	}
	else
	{
		userSelectAll = true;
		for (int i = 0; i < cnt; ++i)
		{
			temp = (ManaUserItem *)(ui.listUser->itemWidget(ui.listUser->item(i)));
			temp->ui.toolButton->setIcon(QIcon(GBK::ToUnicode(":/�û�����С��ť/Resources/С��ť/ѡ��.png")));
			temp->ui.toolButton->setChecked(true);
		}
	}
}

void MgInterface::OnBtnUserBarDelete()
{
	int resure = TipWindow::Information_OKCancel(GBK::ToUnicode("ȷ��ɾ������ѡ���˻���"));
	if (resure)
	{
		vector<string>userOfDelete;
		int cnt = 0;
		ManaUserItem *temp;

		int cnt_a = ui.listUser->count();

		while (cnt < ui.listUser->count())
		{
			temp = (ManaUserItem *)(ui.listUser->itemWidget(ui.listUser->item(cnt)));
			if (temp != nullptr && temp->ui.toolButton->isChecked())
			{
				userOfDelete.push_back(GBK::FromUnicode(ui.listUser->item(cnt)->data(Qt::UserRole + 1).toString()));
				delete ui.listUser->takeItem(cnt);
			}
			else
			{
				++cnt;
			}
		}
		if (userOfDelete.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��δ��ѡ�κ��˻�������"));
			return;
		}
		FileManage::DeleteUser(userOfDelete);

		listItemUser = FileManage::userData;
		AddToListLeft(FileManage::userData);
		AddToListRight(FileManage::bookData);
	}
}

void MgInterface::OnBtnUserBarOKClicked()
{
	int resure = TipWindow::Information_OKCancel(GBK::ToUnicode("ȷ���޸ĵ�ǰ�˻���"));
	if (resure)
	{
		string name = GBK::FromUnicode(ui.userBarName->text());
		string sex = GBK::FromUnicode(ui.userBarSex->text());
		string institute = GBK::FromUnicode(ui.userBarInstitute->text());
		string className = GBK::FromUnicode(ui.userBarClass->text());

		//��֤�Ƿ�Ϊ��
		if (name.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��������Ϊ�գ�����"));
			return;
		}
		if (institute.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("ѧԺ����Ϊ�գ�����"));
			return;
		}
		if (className.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�༶����Ϊ�գ�����"));
			return;
		}

		//��֤�ո�
		if (!IsHaveSpace(name, "����"))
		{
			return;
		}
		if (!IsHaveSpace(institute, "ѧԺ"))
		{
			return;
		}
		if (!IsHaveSpace(className, "�༶"))
		{
			return;
		}

		//��֤�Ա��ʽ
		if (!(sex == "��" || sex == "Ů"))
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�Ա������ʽ����ȷ�����������л�Ů������"));
		}

		QListWidgetItem *temp = ui.listUser->currentItem();
		bool flag = false;
		if (GBK::ToUnicode(name) != temp->data(Qt::UserRole + 3).toString() ||
			GBK::ToUnicode(institute) != temp->data(Qt::UserRole + 5).toString() ||
			GBK::ToUnicode(className) != temp->data(Qt::UserRole + 6).toString())
		{
			flag = true;
		}
		if ((sex == "��" && GBK::ToUnicode("��") != temp->data(Qt::UserRole + 4).toString()) && (sex == "Ů" && GBK::ToUnicode("Ů") != temp->data(Qt::UserRole + 4).toString()))
		{
			flag = true;
		}

		//�û��޸�������
		if (flag)
		{
			//����Ϊ�������޸�
			//�޸�ListWidget�е�����
			ManaUserItem *tempWidget = (ManaUserItem *)(ui.listUser->itemWidget(temp));
			tempWidget->ui.ID->setText(GBK::ToUnicode(name));
			tempWidget->ui.sex->setText(GBK::ToUnicode(sex));
			tempWidget->ui.institute->setText(GBK::ToUnicode(institute));
			tempWidget->ui.className->setText(GBK::ToUnicode(className));

			//�޸�userData�е�����
			UserItem *tUserItem = FileManage::SelectUser(GBK::FromUnicode(temp->data(Qt::UserRole + 1).toString()));
			tUserItem->name = name;
			tUserItem->institute = institute;
			tUserItem->className = className;
			if (sex == "��")
			{
				tUserItem->sex = 1;
			} 
			else
			{
				tUserItem->sex = 0;
			}

			listItemUser = FileManage::userData;

			//�޸��ļ��е�����
			FileManage::WriteToUser_Txt();
		}
		else//�û�δ�޸�����
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("��δ�޸��κ�����ֵ������"));
			return;
		}
	}
}


//-------------------------------------------�û�����---------------------------------------------------------
//��갴���¼�
void MgInterface::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//�����϶��¼�
void MgInterface::mouseMoveEvent(QMouseEvent *event)
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
void MgInterface::mouseReleaseEvent(QMouseEvent *event)
{
	//���δ����
	isMousePressed = false;
	event->accept();
}

void MgInterface::OnBtnCloseClicked()
{
	this->close();
}

void MgInterface::OnBtnMinClicked()
{
	this->showMinimized();
}
