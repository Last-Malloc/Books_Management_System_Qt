#include "HeadPor.h"

HeadPor::HeadPor(QWidget *parent)
	: QFrame(parent)
{
}

HeadPor::~HeadPor()
{
}

void HeadPor::GetIconName(QString a)
{
	headPorName = a;
	update();	
}

void HeadPor::paintEvent(QPaintEvent *event)
{
	QPainter myPen(this);

	int wid = this -> width();
	int hei = this->height();
	touXiang.load(headPorName);
	int len;
	if (touXiang.width() < height())
	{
		len = touXiang.width();
	} 
	else
	{
		len = touXiang.height();
	}
	myPen.drawPixmap(0, 0, this->width(), this->height(), touXiang, 0, 0, touXiang.width(), touXiang.height());
} 