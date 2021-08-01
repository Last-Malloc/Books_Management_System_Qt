#include "BMS.h"

BMS::BMS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	isMousePressed = false;
//--------------------------------------------数据加载-----------------------------------------------------
	FileManage::ReLoadAll();
//--------------------------------------------信号合槽---------------------------------------------------------	
	connect(ui.lgID, SIGNAL(editTextChanged(QString)), this, SLOT(OnLgIDEditChanged(QString)));
	connect(ui.lgPW, SIGNAL(returnPressed()), this, SLOT(OnLgOKClicked()));
	connect(ui.lgOK, SIGNAL(clicked()), this, SLOT(OnLgOKClicked()));
	connect(ui.lgShowPW, SIGNAL(clicked()), this, SLOT(OnLgShowPWChanged()));

	connect(ui.remberPW, SIGNAL(stateChanged(int)), this, SLOT(OnRemberPWElected(int)));
	connect(ui.lgRegister, SIGNAL(clicked()), this, SLOT(OnLgRegisterClicked()));
	connect(ui.lgFindPW, SIGNAL(clicked()), this, SLOT(OnLgFindPWClicked()));

	//自定义按钮
	connect(ui.lgClose, SIGNAL(clicked()), this, SLOT(OnBtnCloseClicked()));
	connect(ui.lgMininum, SIGNAL(clicked()), this, SLOT(OnBtnMinClicked()));
	connect(ui.lgSet, SIGNAL(clicked()), this, SLOT(OnBtnSetClicked()));
	//发射头像文件名
	connect(this, SIGNAL(SendIconName(QString)), ui.lgFramePNG, SLOT(GetIconName(QString)));
//------------------------------------------------初始化----------------------------------------------------------
	//初始化ID输出框
	AddItemToLgID();

	//初始化头像
	if (FileManage::recentData.size() > 0)
	{
		emit SendIconName(GBK::ToUnicode(FileManage::recentData[0].iconName));
	}
	else
	{
		emit SendIconName(GBK::ToUnicode("./headpor/moren.png"));//默认头像
	}

	//初始化密码（若当前账号记住密码）并初始化成员变量rememberFlag（1为记住密码）
	if (FileManage::recentData.size() > 0 && FileManage::recentData[0].rembPW)
	{
		rememberFlag = 1;
		ui.remberPW->setCheckState(Qt::Checked);
		ui.lgPW->setEchoMode(QLineEdit::Password);
		ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/小按钮/Resources/小按钮/隐藏密码.png")));
		showPwFlag = 0;
		ui.lgPW->setText(GBK::ToUnicode(FileManage::SelectUser(FileManage::recentData[0].ID)->password));		
	}
	else
	{
		ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/小按钮/Resources/小按钮/显示密码.png")));
		showPwFlag = 1;
		rememberFlag = 0;
	}
}

BMS::~BMS()
{
}

//------------------------------------------------------------------------------------------------------------------
//将ID输入框中的值与rencent数据比对做出相应的反应
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

		if (tempRecent)//输入ID在recent中
		{
			emit SendIconName(GBK::ToUnicode(tempRecent->iconName));
			if (tempRecent->rembPW)
			{
				ui.remberPW->setCheckState(Qt::Checked);
				ui.lgPW->setEchoMode(QLineEdit::Password);
				ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/小按钮/Resources/小按钮/隐藏密码.png")));
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
			if (tempUser)//该ID账户存在user中
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

void BMS::OnLgOKClicked()//登录按钮
{
	//验空
	QString lgUserName = ui.lgID->currentText();
	QString lgPassword = ui.lgPW->text();
	if (lgUserName.isEmpty() && lgPassword.isEmpty())
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("用户名、密码不能为空！！！"));
		return;
	}
	else if (lgUserName.isEmpty())
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("用户名不能为空！！！"));
		return;
	}
	else if (lgPassword.isEmpty())
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("密码不能为空！！！"));
		return;
	}
	if (!IsHaveSpace(GBK::FromUnicode(lgUserName), "用户名"))
	{
		return;
	}
	if (!IsHaveSpace(GBK::FromUnicode(lgPassword), "密码"))
	{
		return;
	}
	//ID存在于user中
	if (tempUser)
	{
		//密码正确
		if (tempUser->password == GBK::FromUnicode(lgPassword))
		{
			//登录人员为管理员（普通/最高管理员）
			if (tempUser->power)
			{
				this->hide();
				mgJiemian = new MgInterface(*tempUser);
				connect(mgJiemian, SIGNAL(ZhuxiaoOrExit(int)), this, SLOT(OnZhuXiaoExit(int)));
				mgJiemian->show();//此处界面show之后tempRecent和tempUser指针指向内容可能已被修改
			} 
			else//登录人员为普通用户
			{
				this->hide();
				userJiemian = new UserInterface(*tempUser);
				connect(userJiemian, SIGNAL(ZhuxiaoOrExit(int)), this, SLOT(OnZhuXiaoExit(int)));
				userJiemian->show();//此处界面show之后tempRecent和tempUser指针指向内容可能已被修改
			}

			//更改登录账户的记住密码设置 或 将该未登录过的账户记录到recent中
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

			//账号登陆过
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
			else//账号没有登陆过
			{
				RecentItem re{ tempUser->ID, tempUser->iconName, remenber };
				FileManage::AddRecent(re);
			}

		} 
		else//密码错误
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("密码错误，请重新输入！！！"));
		}
	}
	else//ID不存在
	{	
		TipWindow::Information_OnlyOK(GBK::ToUnicode("该账号不存在！！！"));
	}
}

void BMS::OnZhuXiaoExit(int flag)
{
	if (flag == 1)//用户选择了注销
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

void BMS::OnLgRegisterClicked()//注册按钮
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

void BMS::OnLgFindPWClicked()//找回密码按钮
{
	findPW = new FindPassword;
	this->hide();
	findPW->exec();
	this->show();
	delete findPW;
}

//记住密码按钮(仅更改标志，反应并入确定按钮)
void BMS::OnRemberPWElected(int state)
{
	if (ui.remberPW->isChecked())//选上
	{
		rememberFlag = 1;
	}
	else
	{
		rememberFlag = 0;
	}
}

//最近登录账户装入ID窗口控件
void BMS::AddItemToLgID()
{
	ui.lgID->clear();
	for (int i = 0; i < FileManage::recentData.size(); ++i)
	{
		ui.lgID->addItem(QIcon(GBK::ToUnicode(FileManage::recentData[i].iconName)), GBK::ToUnicode(FileManage::recentData[i].ID));
	}
}

// 显示/隐藏密码（不可查看已记住的密码）
void BMS::OnLgShowPWChanged()
{
	if (showPwFlag == 0)
	{
		if (tempRecent != nullptr && tempRecent->rembPW == 1)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("不可查看已记住的密码！！！"));
			return;
		}
		ui.lgPW->setEchoMode(QLineEdit::Normal);
		ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/小按钮/Resources/小按钮/显示密码.png")));
		showPwFlag = 1;
	}
	else
	{
		ui.lgPW->setEchoMode(QLineEdit::Password);
		ui.lgShowPW->setIcon(QIcon(GBK::ToUnicode(":/小按钮/Resources/小按钮/隐藏密码.png")));
		showPwFlag = 0;
	}
}

//-------------------------------------------用户体验--------------------------------------------------------------
//自定义关闭，最小化，设置按钮
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

//鼠标按下事件
void BMS::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//窗体拖动事件
void BMS::mouseMoveEvent(QMouseEvent *event)
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
void BMS::mouseReleaseEvent(QMouseEvent *event)
{
	//鼠标未按下
	isMousePressed = false;
	event->accept();
}
