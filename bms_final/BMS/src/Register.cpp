#include "Register.h"
#include <QFileDialog>
#include <QMessageBox>
#include "TipWindow.h"
#include "FileManage.h"

Register::Register(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	headName = GBK::ToUnicode("./headpor/moren.png");
	ui.checkBUser->setChecked(true);
	ui.radioSexMan->setChecked(true);
	isMousePressed = false;

	//--------------------------------------------------信号合槽--------------------------
	connect(this, SIGNAL(SendIconName(QString)), ui.frame, SLOT(GetIconName(QString)));
	connect(ui.btnCHead, SIGNAL(clicked()), this, SLOT(OnBtnCHeadClicked()));
	connect(ui.checkBUser, SIGNAL(stateChanged(int)), this, SLOT(OnCheckBUserElected(int)));
	connect(ui.checkBMan, SIGNAL(stateChanged(int)), this, SLOT(OnCheckBManElected(int)));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(OnBtnOKClicked()));
	connect(ui.btnCancel,SIGNAL(clicked()),this,SLOT(OnBtnCancelClicked()));

	emit SendIconName(headName);//默认头像
}

Register::~Register()
{
}

void Register::OnBtnCHeadClicked()
{
	headName = QFileDialog::getOpenFileName(this,GBK::ToUnicode("选择头像"),GBK::ToUnicode("*.jpg;;*.png"));
	if (headName.isEmpty())
	{
		headName = GBK::ToUnicode("./headpor/moren.png");
	}
	emit SendIconName(headName);
}

void Register::OnCheckBUserElected(int)
{
	if (ui.checkBUser->isChecked())
	{
		ui.checkBMan->setChecked(false);
	} 
	else
	{
		ui.checkBMan->setChecked(true);
	}
}

void Register::OnCheckBManElected(int)
{
	if (ui.checkBMan->isChecked())
	{
		ui.checkBUser->setChecked(false);
	} 
	else
	{
		ui.checkBUser->setChecked(true);
	}
}

void Register::OnBtnOKClicked()
{
	//使用FileManage类的容错
	string tID = GBK::FromUnicode(ui.lineID->text());
	string tPW = GBK::FromUnicode(ui.linePassWord->text());
	int tPower;
	if (ui.checkBUser->isChecked())
	{
		tPower = 0;
	} 
	else
	{
		tPower = 1;
	}
	string tName = GBK::FromUnicode(ui.lineName->text());
	int tSex;
	if (ui.radioSexMan->isChecked())
	{
		tSex = 1;
	} 
	else
	{
		tSex = 0;
	}
	string tInstitute = GBK::FromUnicode(ui.lineInstitute->text());
	string tClassName = GBK::FromUnicode(ui.lineClassName->text());
	string tIconName = GBK::FromUnicode(headName);
	string tScProt;
	if (ui.cbQuestion->currentText() == GBK::ToUnicode("不设置密保"))
	{
		tScProt = "";
	}
	else
	{
		tScProt = GBK::FromUnicode(ui.cbQuestion->currentText());
	}
	string tAnswer = GBK::FromUnicode(ui.lineAnswer->text());

	UserItem tUser{ tID, tPW, tPower, tName, tSex, tInstitute,tClassName, tIconName, tScProt, tAnswer };
	bool flag =  FileManage::InspectUser(tUser);
	if (flag)
	{
		if (tPower)
		{
			FileManage::AddMessage(tUser);
			TipWindow::Information_OnlyOK(GBK::ToUnicode("已提交申请，等待最高管理员的审批！！！"));
		} 
		else
		{
			FileManage::AddUser(tUser);
			TipWindow::Information_OnlyOK(GBK::ToUnicode("申请成功，请返回登录界面登录！！！"));
		}
	}
}

void Register::OnBtnCancelClicked()
{
	reject();
}

//鼠标按下事件
void Register::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//窗体拖动事件
void Register::mouseMoveEvent(QMouseEvent *event)
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
void Register::mouseReleaseEvent(QMouseEvent *event)
{
	//鼠标未按下
	isMousePressed = false;
	event->accept();
}