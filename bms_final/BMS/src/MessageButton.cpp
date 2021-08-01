#include "MessageButton.h"

MessageButton::MessageButton(QWidget *parent)
	: QToolButton(parent)
{
}

MessageButton::~MessageButton()
{
}

void MessageButton::paintEvent(QPaintEvent *event)
{
	QPainter myPen(this);

	QPixmap p;
	p.load(GBK::ToUnicode(":/用户界面小按钮/Resources/小按钮/信息.png"));
	p = p.scaled(60, 50);
	myPen.drawPixmap(10, 10, this->width() - 20, this->height() - 20, p, 0, 0, this->width(), this->height());

	int nn = FileManage::messageData.size();
	if (nn > 0)
	{
		myPen.setBrush(Qt::red);
		myPen.drawEllipse(0, 5, 25, 25);

		QRect rect(3, 7, 21, 21);
		QFont font(GBK::ToUnicode("黑体"), 10, QFont::Bold);
		myPen.setFont(font);
		myPen.setPen(Qt::white);
		QString n = QString::number(nn);
		myPen.drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, n);
	}
}
