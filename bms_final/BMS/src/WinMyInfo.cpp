#include "WinMyInfo.h"
#include <QFileDialog>

WinMyInfo::WinMyInfo(UserItem us, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//成员变量初始化
	isMousePressed = false;

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	tempUserItem = us;
	tempIconName = GBK::ToUnicode(tempUserItem.iconName);
	ui.frame->headPorName = GBK::ToUnicode(tempUserItem.iconName);
	ui.frame->update();
	
	if (tempUserItem.power == 0)
	{
		ui.label_6->setText(GBK::ToUnicode("普通用户"));
	} 
	else
	{
		if (tempUserItem.power == 1)
		{
			ui.label_6->setText(GBK::ToUnicode("普通管理员"));
		} 
		else
		{
			ui.label_6->setText(GBK::ToUnicode("最高管理员"));
		}
	}

	ui.label_2->setText(GBK::ToUnicode("学号：" + tempUserItem.ID));

	if (tempUserItem.sex)
	{
		ui.label->setText(GBK::ToUnicode("姓名：" + tempUserItem.name + "    性别：男"));
	} 
	else
	{
		ui.label->setText(GBK::ToUnicode("姓名：" + tempUserItem.name + "    性别：女"));
	}
	
	ui.label_3->setText(GBK::ToUnicode(tempUserItem.institute + "                    " + tempUserItem.className));

	if (tempUserItem.scProt == "##")
	{
		ui.lineAnswer->setEnabled(false);
	} 
	else
	{
		ui.cbQuestion->setCurrentText(GBK::ToUnicode(tempUserItem.scProt));
		ui.lineAnswer->setText(GBK::ToUnicode(tempUserItem.answer));
	}

	//-------------------------------------信号合槽----------------------------------------	
	connect(ui.btnCHead, SIGNAL(clicked()), this, SLOT(OnBtnCHeadClicked()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(OnBtnCancelClicked()));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(OnBtnOKClicked()));
	connect(ui.cbQuestion, SIGNAL(currentTextChanged(QString)), this, SLOT(OnCbQuestionTextChanged(QString)));
}

WinMyInfo::~WinMyInfo()
{
}

void WinMyInfo::OnBtnCHeadClicked()
{
	tempIconName = QFileDialog::getOpenFileName(this, GBK::ToUnicode("选择头像"), GBK::ToUnicode("*.jpg;;*.png"));
	if (!(tempIconName.isEmpty()))
	{
		ui.frame->headPorName = tempIconName;
		ui.frame->update();
	}
}

void WinMyInfo::OnBtnOKClicked()
{
	bool flag = false;
	if (tempIconName != GBK::ToUnicode(tempUserItem.iconName))
	{
		flag = true;
	}

	string tempScProt;
	string tempAnswer;
	if (ui.cbQuestion->currentText() == GBK::ToUnicode("不设置密保"))
	{
		tempAnswer = tempScProt = "##";
		if (tempScProt != tempUserItem.scProt)
		{
			flag = true;
		}
	} 
	else
	{
		tempScProt = GBK::FromUnicode(ui.cbQuestion->currentText());
		if (tempScProt.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("密保问题不能为空！！！"));
			return;
		}
		if (!IsHaveSpace(tempScProt, "密保问题"))
		{
			return;
		}

		tempAnswer = GBK::FromUnicode(ui.lineAnswer->text());
		if (tempAnswer.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("密保答案不能为空！！！"));
			return;
		}
		if (!IsHaveSpace(tempAnswer, "密保答案"))
		{
			return;
		}

		if (tempScProt != tempUserItem.scProt || tempAnswer != tempUserItem.answer)
		{
			flag = true;
		}
		if (flag)
		{
			int queRen = TipWindow::Information_OKCancel(GBK::ToUnicode("确认您的更改信息?"));
			if (queRen)
			{
				FileManage::AlterUser(tempUserItem.ID, EleUser::iconName, GBK::FromUnicode(tempIconName));
				FileManage::AlterUser(tempUserItem.ID, EleUser::scProt, tempScProt);
				FileManage::AlterUser(tempUserItem.ID, EleUser::answer, tempAnswer);
				accept();
			}
		}
	}
}

void WinMyInfo::OnBtnCancelClicked()
{
	reject();
}

void WinMyInfo::OnCbQuestionTextChanged(QString qstr)
{
	if (qstr == GBK::ToUnicode("不设置密保"))
	{
		ui.lineAnswer->clear();
		ui.lineAnswer->setEnabled(false);
	}
	else
	{
		ui.lineAnswer->setEnabled(true);
	}
}

//-------------------------------------------用户体验---------------------------------------------------------
//鼠标按下事件
void WinMyInfo::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//窗体拖动事件
void WinMyInfo::mouseMoveEvent(QMouseEvent *event)
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
void WinMyInfo::mouseReleaseEvent(QMouseEvent *event)
{
	//鼠标未按下
	isMousePressed = false;
	event->accept();
}
