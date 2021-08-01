#pragma once

/*����������ʾ���ڣ�����ʹ�þ�̬����
		Information_OnlyOK(const QString &)//ֻ��ȷ������ʾ����
		Information_OKCancel(const QString &);//����ȷ����ȡ������ʾ���ڣ�����ֵ1Ϊȷ����0Ϊȡ�� */

#include <QDialog>
#include "ui_TipWindow.h"
#include <QtGui>
#include "GBK.h"
#include <Windows.h>
#include <WinUser.h>
#include <iostream>

class TipWindow : public QDialog
{
	Q_OBJECT

public:
	TipWindow(int flag, const QString &title, QWidget *parent = Q_NULLPTR);
	~TipWindow();

	static void Information_OnlyOK(const QString &);
	static int Information_OKCancel(const QString &);//����ֵ1Ϊȷ�ϣ�0Ϊȡ��

private:
	Ui::TipWindow ui;

private:
	QString title;
	void paintEvent(QPaintEvent *event);
	void timerEvent(QTimerEvent *event);

private slots:
	void OnBtnOKClicked();
	void OnBtnCancelClicked();

private:
	//ʵ�ִ��ڿ��϶�
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //�������ڴ����λ��
	bool isMousePressed;    //����Ƿ���
	int countt;
	int timeID;
};
