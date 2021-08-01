#pragma once

#include <QDialog>
#include <QtGui>
#include "ui_FindPassword.h"
#include "GBK.h"
#include "FileManage.h"

class FindPassword : public QDialog
{
	Q_OBJECT

public:
	FindPassword(QWidget *parent = Q_NULLPTR);
	~FindPassword();

private slots:
	void OnOKClicked();//确定按钮
	void OnBackClicked();//返回按钮
	void OnLgIDEditChanged(QString);//账号输入框变化响应

public:
	Ui::FindPassword ui;

	UserItem* tUser;

	//重置密码状态位，用来改变确定按钮的响应
	int czFlag;

	//实现窗口可拖动
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //鼠标相对于窗体的位置
	bool isMousePressed;    //鼠标是否按下
};
