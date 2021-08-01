#include "TipWindow.h"

TipWindow::TipWindow(int flag, const QString &title, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	isMousePressed = false;

	countt = 0;
	timeID = startTimer(500);

	this->title = title;

	//1表示窗口包含确定和取消按钮；0只包含确定按钮
	if (!flag)
	{
		ui.Cancel->hide();
		ui.OK->setGeometry(76, 180, 231, 61);
	}

	connect(ui.OK, SIGNAL(clicked()), this, SLOT(OnBtnOKClicked()));
	connect(ui.Cancel, SIGNAL(clicked()), this, SLOT(OnBtnCancelClicked()));
}

TipWindow::~TipWindow()
{

}

void TipWindow::Information_OnlyOK(const QString &text)
{
	TipWindow temp(0, text);
	temp.exec();
}

int TipWindow::Information_OKCancel(const QString &text)
{
	TipWindow temp(1, text);
	int rtFlag = temp.exec();
	if (rtFlag == QDialog::Accepted)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void TipWindow::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	// 设置颜色 
	painter.setPen(QColor(255, 255, 255));

	// 设置字体
	QFont font(GBK::ToUnicode("黑体"), 18, QFont::Bold);
	painter.setFont(font);

	QRect rect(30, 20, 291, 141);

	// 设置option
	QTextOption option;
	option.setWrapMode(QTextOption::WrapAnywhere);
	painter.drawText(rect, title, option);

	QRect all(0, 0, this->width(), this->height());

	if (countt < 100)
	{
		if (countt % 2)
		{
			painter.setBrush(QColor(173, 174, 41, 30));
			painter.drawRect(all);
		}
		else
		{
			painter.setBrush(QColor(0, 255, 0, 30));
			painter.drawRect(all);
		}
	}
}

void TipWindow::OnBtnOKClicked()
{
	accept();
}

void TipWindow::OnBtnCancelClicked()
{
	reject();
}

//鼠标按下事件
void TipWindow::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//窗体拖动事件
void TipWindow::mouseMoveEvent(QMouseEvent *event)
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
void TipWindow::mouseReleaseEvent(QMouseEvent *event)
{
	//鼠标未按下
	isMousePressed = false;
	event->accept();
}

void TipWindow::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == timeID)
	{
		if (!countt)
		{
			++countt;
			std::cout << '\a';
		}
		else if (countt < 5)
		{
			++countt;
		}
		else if (countt == 5)
		{
			countt = 101;
			killTimer(timeID);
		}
		update();
	}
}