#pragma once

#include <QDialog>
#include "ui_Register.h"
#include <QtGui>
#include "GBK.h"
#include <string>
#include <cctype>
#include "FileManage.h"

using namespace std;

class Register : public QDialog
{
	Q_OBJECT

public:
	Register(QWidget *parent = Q_NULLPTR);
	~Register();

private:
	Ui::Register ui;

signals:
	void SendIconName(QString);

private slots:
	void OnBtnCHeadClicked();
	void OnCheckBUserElected(int);
	void OnCheckBManElected(int);
	void OnBtnOKClicked();
	void OnBtnCancelClicked();

private:
	QString headName;

	//ʵ�ִ��ڿ��϶�
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //�������ڴ����λ��
	bool isMousePressed;    //����Ƿ���
};
