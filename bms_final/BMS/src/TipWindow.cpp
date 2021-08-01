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

	//1��ʾ���ڰ���ȷ����ȡ����ť��0ֻ����ȷ����ť
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

	// ������ɫ 
	painter.setPen(QColor(255, 255, 255));

	// ��������
	QFont font(GBK::ToUnicode("����"), 18, QFont::Bold);
	painter.setFont(font);

	QRect rect(30, 20, 291, 141);

	// ����option
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

//��갴���¼�
void TipWindow::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//�����϶��¼�
void TipWindow::mouseMoveEvent(QMouseEvent *event)
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
void TipWindow::mouseReleaseEvent(QMouseEvent *event)
{
	//���δ����
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