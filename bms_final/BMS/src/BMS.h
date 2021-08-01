#pragma once

/*本类为登录窗口*/

#include <QtWidgets/QMainWindow>
#include "ui_BMS.h"
#include <QtGui>
#include <fstream>
#include <vector>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "FileManage.h"
#include "MgInterface.h"
#include "UserInterface.h"
#include "TipWindow.h"
#include "FindPassword.h"
#include "Register.h"
#include "GBK.h"

class BMS : public QMainWindow
{
	Q_OBJECT

public:
	BMS(QWidget *parent = Q_NULLPTR);
	~BMS();

signals:
	void SendIconName(QString);//设置头像

private:
	Ui::BMSClass ui;

//----------------------------------------------------------------------------------------------------

private slots:
	//响应函数
	void OnLgIDEditChanged(QString);//账号输入框变化响应
	void OnLgOKClicked();//登录按钮响应
	void OnLgRegisterClicked();//注册账号按钮响应
	void OnLgFindPWClicked();//找回密码按钮响应
	void OnRemberPWElected(int);//记住密码按钮响应
	void OnLgShowPWChanged();//显示/隐藏密码响应
	void OnZhuXiaoExit(int);//用户界面注销/退出的响应函数

private:
	void AddItemToLgID();//向ID输入框添加访问过的账户

//---------------------------------------标志位--------------------------
	int rememberFlag;//记住密码的标志
	int showPwFlag;//显示密码为1

//---------------------------------------存储当前ID所对应元数据--------------------------
	UserItem *tempUser;
	RecentItem *tempRecent;
	//暂时存储tempRecent和tempUser中人员结构的ID以防止两指针指向的数据被其他方式改变
	string ttUser,ttRecent;
	
//---------------------------------------子窗口--------------------------
	MgInterface *mgJiemian;//管理员界面
	UserInterface *userJiemian;//用户界面
	FindPassword *findPW;//找回密码界面
	Register *regt;//用户注册界面

//-----------------------------------------用户体验--------------------------------------------------------	
private slots:
	//自定义最小化、关闭、设置按钮
	void OnBtnCloseClicked();
	void OnBtnMinClicked();
	void OnBtnSetClicked();
private:
	//实现窗口可拖动
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //鼠标相对于窗体的位置
	bool isMousePressed;    //鼠标是否按下
};
