#include "BMS.h"
#include <QtWidgets/QApplication>
#include "AfCd.h"

int main(int argc, char *argv[])
{
	AfCd::cd();
	QApplication a(argc, argv);
	BMS w;
	//�ޱ߿򴰿�
	w.setWindowFlags(Qt::FramelessWindowHint);
	w.show();
	return a.exec();
}
