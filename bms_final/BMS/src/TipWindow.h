#pragma once

/*本类用作提示窗口，仅可使用静态函数
		Information_OnlyOK(const QString &)//只有确定的提示窗口
		Information_OKCancel(const QString &);//包含确定和取消的提示窗口：返回值1为确定，0为取消 */

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
	static int Information_OKCancel(const QString &);//返回值1为确认，0为取消

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
	//实现窗口可拖动
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //鼠标相对于窗体的位置
	bool isMousePressed;    //鼠标是否按下
	int countt;
	int timeID;
};
