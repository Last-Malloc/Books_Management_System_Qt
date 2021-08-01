#pragma once

#include <QFrame>
#include <QtGui>

//该类用作显示头像，需在要显示头像的类中定义信号
//并连接本类槽函数GetIconName(QString)

class HeadPor : public QFrame
{
	Q_OBJECT

public:
	HeadPor(QWidget *parent);
	~HeadPor();

	void paintEvent(QPaintEvent *event);

private slots:
	void GetIconName(QString);

public:
	QString headPorName;//头像名
	QPixmap touXiang;
};
