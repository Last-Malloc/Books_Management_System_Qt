#include "FindPassword.h"
#include "TipWindow.h"

FindPassword::FindPassword(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	//初始化
	ui.radioZH->setChecked(true);
	tUser = nullptr;
	czFlag = 0;
	isMousePressed = false;

	connect(ui.lineID, SIGNAL(textChanged(QString)), this, SLOT(OnLgIDEditChanged(QString)));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(OnOKClicked()));
	connect(ui.btnBack, SIGNAL(clicked()), this, SLOT(OnBackClicked()));
}

FindPassword::~FindPassword()
{
}

void FindPassword::OnLgIDEditChanged(QString temp)
{
	ui.lineAnswer->setEnabled(true);
	ui.label_3->clear();
	if (temp.size() == 10)
	{
		tUser = FileManage::SelectUser(GBK::FromUnicode(temp));
		if (tUser)
		{
			if (tUser->scProt == "##")
			{
				ui.label_3->setText(GBK::ToUnicode("您未设置密保，请于管理员处重置密码！！！"));
				ui.lineAnswer->setEnabled(false);
			} 
			else
			{
				ui.label_3->setText(GBK::ToUnicode(tUser->scProt));
			}
		} 
		else
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("该账号不存在，请重新输入！！！"));
		}
	}
}

void FindPassword::OnOKClicked()
{
	if (czFlag == 0)
	{
		if (ui.lineID->text().size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("用户名不能为空！！！"));
			return;
		}
		if (!IsHaveSpace(GBK::FromUnicode(ui.lineID->text()), "用户名"))
		{
			return;
		}
		if (tUser == nullptr)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("用户名不存在！！！"));
			return;
		}
		if (ui.lineAnswer->text().size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("密保不能为空！！！"));
			return;
		}
		if (!IsHaveSpace(GBK::FromUnicode(ui.lineAnswer->text()), "密保"))
		{
			return;
		}
	}
	if (czFlag)
	{
		if (ui.lineID->text().isEmpty())
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("新密码不能为空！！！"));
			return;
		}
		if (!IsHaveSpace(GBK::FromUnicode(ui.lineID->text()), "新密码"))
		{
			return;
		}
		if (ui.lineAnswer->text().isEmpty())
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("确认密码不能为空！！！"));
			return;
		}
		if (!IsHaveSpace(GBK::FromUnicode(ui.lineAnswer->text()), "确认密码"))
		{
			return;
		}
		if (ui.lineID->text() != ui.lineAnswer->text())
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("两次密码不一致，请重新输入！！！"));
			return;
		}
		if (FileManage::AlterUser(tUser->ID, EleUser::password, GBK::FromUnicode(ui.lineID->text())))
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("密码修改成功，新密码为") + ui.lineID->text());
		}
		return;
	}
	if (tUser != nullptr)
	{
		if (tUser->scProt != "##")
		{
			if (tUser->answer == GBK::FromUnicode(ui.lineAnswer->text()))
			{
				if (ui.radioZH->isChecked())
				{
					TipWindow::Information_OnlyOK(GBK::ToUnicode("您的密码为：" + tUser->password));
				} 
				else
				{
					czFlag = 1;
					ui.label_3->hide();
					ui.label->setText(GBK::ToUnicode("新密码"));
					ui.label->move(70, 60);
					ui.label_2->setText(GBK::ToUnicode("确认密码"));
					ui.label_2->move(40, 120);
					ui.lineID->setPlaceholderText(GBK::ToUnicode("请输入新密码"));
					ui.lineID->move(150, 60);
					ui.lineAnswer->setPlaceholderText(GBK::ToUnicode("请重新输入新密码"));
					ui.lineAnswer->move(150, 120);
					ui.radioCZ->hide();
					ui.radioZH->hide();
					ui.btnOK->move(140, 200);
					ui.lineID->clear();
					ui.lineAnswer->clear();
				}
			} 
			else
			{
				TipWindow::Information_OnlyOK(GBK::ToUnicode("密保错误，请重新输入！！！"));
			}
		}
	}
}

void FindPassword::OnBackClicked()
{
	accept();
}

//鼠标按下事件
void FindPassword::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//窗体拖动事件
void FindPassword::mouseMoveEvent(QMouseEvent *event)
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
void FindPassword::mouseReleaseEvent(QMouseEvent *event)
{
	//鼠标未按下
	isMousePressed = false;
	event->accept();
}