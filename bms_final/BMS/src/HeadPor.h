#pragma once

#include <QFrame>
#include <QtGui>

//����������ʾͷ������Ҫ��ʾͷ������ж����ź�
//�����ӱ���ۺ���GetIconName(QString)

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
	QString headPorName;//ͷ����
	QPixmap touXiang;
};
