#include "BMS.h"

BMS::BMS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	isMousePressed = false;
//--------------------------------------------���ݼ���-----------------------------------------------------
	FileManage::ReLoadAll();
//--------------------------------------------�źźϲ�---------------------------------------------------------	
	connect(ui.lgID, SIGNAL(editTextChanged(QString)), this, SLOT(OnLgIDEditChanged(QString)));
	connect(ui.lgPW, SIGNAL(returnPressed()), this, SLOT(OnLgOKClicked()));
	connect(ui.lgOK, SIGNAL(clicked()), this, SLOT(OnLgOKClicked()));
	connect(ui.lgShowPW, SIGNAL(clicked()), this, SLOT(OnLgShowPWChanged()));

	connect(ui.remberPW, SIGNAL(stateChanged(int)), this, SLOT(OnRemberPWElected(int)));
	connect(ui.lgRegister, SIGNAL(clicked()), this, SLOT(OnLgRegisterClicked()));
	connect(ui.lgFindPW, SIGNAL(clicked()), this, SLOT(OnLgFindPWClicked()));

	//�Զ��尴ť
	connect(ui.lgClose, SIGNAL(clicked()), this, SLOT(OnBtnCloseClicked()));
	connect(ui.lgMininum, SIGNAL(clicked()), this, SLOT(OnBtnMinClicked()));
	connect(ui.lgSet, SIGNAL(clicked()), this, SLOT(OnBtnSetClicked()));
	//����ͷ���ļ���
	connect(this, SIGNAL(SendIconName(QString)), ui.lgFramePNG, SLOT(GetIconName(QString)));
//------------------------------------------------��ʼ��----------------------------------------------------------
	//��ʼ��ID�����
	AddItemToLgID();

	//��ʼ��ͷ��
	if (FileManage::recentData.size() > 0)
	{
		emit SendIconName(GBK::ToUnicode(FileManage::recentData[0].iconName));
	}
	else
	{
		emit SendIconName(GBK::ToUnicode("./headpor/moren.png"));//Ĭ��ͷ��
	}

	//��ʼ�����루����ǰ�˺ż�ס���룩����ʼ����Ա����rememberFlag��1Ϊ��ס���룩
	if (FileManage::recentData.size() > 0 && FileManage::recentData[0].rembPW)
	{
		rememberFlag = 1;
		ui.remberPW->setCheckState(Qt::Checked);
		ui.lgPW->setEchoMode(QLineEdit::Password);
		ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/С��ť/Resources/С��ť/��������.png")));
		showPwFlag = 0;
		ui.lgPW->setText(GBK::ToUnicode(FileManage::SelectUser(FileManage::recentData[0].ID)->password));		
	}
	else
	{
		ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/С��ť/Resources/С��ť/��ʾ����.png")));
		showPwFlag = 1;
		rememberFlag = 0;
	}
}

BMS::~BMS()
{
}

//------------------------------------------------------------------------------------------------------------------
//��ID������е�ֵ��rencent���ݱȶ�������Ӧ�ķ�Ӧ
void BMS::OnLgIDEditChanged(QString qstr)
{
	tempRecent = nullptr;
	tempUser = nullptr;
	ttUser = ttRecent = "";
	if (qstr.size() == 10)
	{
		string str = GBK::FromUnicode(qstr);
		tempRecent = FileManage::SelectRecent(str);
		tempUser = FileManage::SelectUser(str);
		if (tempUser)
		{
			ttUser = tempUser->ID;
		}
		else
		{
			ttUser = "";
		}
		if (tempRecent)
		{
			ttRecent = tempRecent->ID;
		} 
		else
		{
			ttRecent = "";
		}

		if (tempRecent)//����ID��recent��
		{
			emit SendIconName(GBK::ToUnicode(tempRecent->iconName));
			if (tempRecent->rembPW)
			{
				ui.remberPW->setCheckState(Qt::Checked);
				ui.lgPW->setEchoMode(QLineEdit::Password);
				ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/С��ť/Resources/С��ť/��������.png")));
				showPwFlag = 0;
				ui.lgPW->setText(GBK::ToUnicode(tempUser->password));
			}
			else
			{
				ui.remberPW->setCheckState(Qt::Unchecked);
				ui.lgPW->clear();
			}
		} 
		else
		{
			if (tempUser)//��ID�˻�����user��
			{
				emit SendIconName(GBK::ToUnicode(tempUser->iconName));
				ui.remberPW->setCheckState(Qt::Unchecked);
				ui.lgPW->clear();
			}
			else
			{
				emit SendIconName(GBK::ToUnicode("./headpor/moren.png"));
				ui.remberPW->setCheckState(Qt::Unchecked);
				ui.lgPW->clear();
			}
		}
	} 
	else
	{
		ui.remberPW->setCheckState(Qt::Unchecked);
		ui.lgPW->clear();
		emit SendIconName(GBK::ToUnicode("./headpor/moren.png"));
	}
}

void BMS::OnLgOKClicked()//��¼��ť
{
	//���
	QString lgUserName = ui.lgID->currentText();
	QString lgPassword = ui.lgPW->text();
	if (lgUserName.isEmpty() && lgPassword.isEmpty())
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("�û��������벻��Ϊ�գ�����"));
		return;
	}
	else if (lgUserName.isEmpty())
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("�û�������Ϊ�գ�����"));
		return;
	}
	else if (lgPassword.isEmpty())
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("���벻��Ϊ�գ�����"));
		return;
	}
	if (!IsHaveSpace(GBK::FromUnicode(lgUserName), "�û���"))
	{
		return;
	}
	if (!IsHaveSpace(GBK::FromUnicode(lgPassword), "����"))
	{
		return;
	}
	//ID������user��
	if (tempUser)
	{
		//������ȷ
		if (tempUser->password == GBK::FromUnicode(lgPassword))
		{
			//��¼��ԱΪ����Ա����ͨ/��߹���Ա��
			if (tempUser->power)
			{
				this->hide();
				mgJiemian = new MgInterface(*tempUser);
				connect(mgJiemian, SIGNAL(ZhuxiaoOrExit(int)), this, SLOT(OnZhuXiaoExit(int)));
				mgJiemian->show();//�˴�����show֮��tempRecent��tempUserָ��ָ�����ݿ����ѱ��޸�
			} 
			else//��¼��ԱΪ��ͨ�û�
			{
				this->hide();
				userJiemian = new UserInterface(*tempUser);
				connect(userJiemian, SIGNAL(ZhuxiaoOrExit(int)), this, SLOT(OnZhuXiaoExit(int)));
				userJiemian->show();//�˴�����show֮��tempRecent��tempUserָ��ָ�����ݿ����ѱ��޸�
			}

			//���ĵ�¼�˻��ļ�ס�������� �� ����δ��¼�����˻���¼��recent��
			int remenber;
			if (ui.remberPW->isChecked())
			{
				remenber = 1;
			}
			else
			{
				remenber = 0;
			}

			if (ttRecent.empty())
			{
				tempRecent = nullptr;
			}
			else 
			{
				tempRecent = FileManage::SelectRecent(ttRecent);
			}

			tempUser = FileManage::SelectUser(ttUser);

			//�˺ŵ�½��
			if (tempRecent != nullptr)
			{
				if (remenber != tempRecent->rembPW)
				{
					if (remenber)
					{
						FileManage::AlterRecent(tempRecent->ID, rembPW, "1");
					} 
					else
					{
						FileManage::AlterRecent(tempRecent->ID, rembPW, "0");
					}
				}
			}
			else//�˺�û�е�½��
			{
				RecentItem re{ tempUser->ID, tempUser->iconName, remenber };
				FileManage::AddRecent(re);
			}

		} 
		else//�������
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("����������������룡����"));
		}
	}
	else//ID������
	{	
		TipWindow::Information_OnlyOK(GBK::ToUnicode("���˺Ų����ڣ�����"));
	}
}

void BMS::OnZhuXiaoExit(int flag)
{
	if (flag == 1)//�û�ѡ����ע��
	{
		string a = ttUser, b = ttRecent;
		this->show();
		AddItemToLgID();
		ttUser = a; 
		ttRecent = b;
		int index;
		for (int i = 0; i < FileManage::recentData.size(); ++i)
		{
			if (ttUser == FileManage::recentData[i].ID)
			{
				index = i;
				break;
			}
		}
		ui.lgID->setCurrentIndex(index);
	} 
	else
	{
		this->close();
	}
}

void BMS::OnLgRegisterClicked()//ע�ᰴť
{
	regt = new Register;
	this->hide();
	int cnt_1 = FileManage::GetCount(FileCnt::user_txt);
	regt->exec();
	this->show();
	if (cnt_1 != FileManage::GetCount(FileCnt::user_txt))
	{
		ui.remberPW->setChecked(false);
		ui.lgID->insertItem(0, QIcon(GBK::ToUnicode(FileManage::userData.rbegin()->iconName)), GBK::ToUnicode(FileManage::userData.rbegin()->ID));
		ui.lgID->setCurrentIndex(0);
		emit SendIconName(GBK::ToUnicode(FileManage::userData.rbegin()->iconName));
	}
	delete regt;
}

void BMS::OnLgFindPWClicked()//�һ����밴ť
{
	findPW = new FindPassword;
	this->hide();
	findPW->exec();
	this->show();
	delete findPW;
}

//��ס���밴ť(�����ı�־����Ӧ����ȷ����ť)
void BMS::OnRemberPWElected(int state)
{
	if (ui.remberPW->isChecked())//ѡ��
	{
		rememberFlag = 1;
	}
	else
	{
		rememberFlag = 0;
	}
}

//�����¼�˻�װ��ID���ڿؼ�
void BMS::AddItemToLgID()
{
	ui.lgID->clear();
	for (int i = 0; i < FileManage::recentData.size(); ++i)
	{
		ui.lgID->addItem(QIcon(GBK::ToUnicode(FileManage::recentData[i].iconName)), GBK::ToUnicode(FileManage::recentData[i].ID));
	}
}

// ��ʾ/�������루���ɲ鿴�Ѽ�ס�����룩
void BMS::OnLgShowPWChanged()
{
	if (showPwFlag == 0)
	{
		if (tempRecent != nullptr && tempRecent->rembPW == 1)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("���ɲ鿴�Ѽ�ס�����룡����"));
			return;
		}
		ui.lgPW->setEchoMode(QLineEdit::Normal);
		ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/С��ť/Resources/С��ť/��ʾ����.png")));
		showPwFlag = 1;
	}
	else
	{
		ui.lgPW->setEchoMode(QLineEdit::Password);
		ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/С��ť/Resources/С��ť/��������.png")));
		showPwFlag = 0;
	}
}

//-------------------------------------------�û�����--------------------------------------------------------------
//�Զ���رգ���С�������ð�ť
void BMS::OnBtnCloseClicked()
{
	this->close();
}

void BMS::OnBtnMinClicked()
{
	this->showMinimized();
}

void BMS::OnBtnSetClicked()
{
	
}

//��갴���¼�
void BMS::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//�����϶��¼�
void BMS::mouseMoveEvent(QMouseEvent *event)
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
void BMS::mouseReleaseEvent(QMouseEvent *event)
{
	//���δ����
	isMousePressed = false;
	event->accept();
}
