#pragma once

#include <QWidget>
#include "ui_UserInterface.h"
#include <QtGui>
#include <string>
#include "GBK.h"
#include "User.h"
#include "BookItemDrawer.h"
#include "WinMyInfo.h"
#include "MyLoanItem.h"

using namespace std;

class UserInterface : public QWidget, public User
{
	Q_OBJECT

public:
	UserInterface(UserItem us, QWidget *parent = Q_NULLPTR);
	~UserInterface();

	//快捷键
	void keyPressEvent(QKeyEvent *event);

private:
	Ui::UserInterface ui;

public:
	//向列表控件添加书籍（并且flag为true时向列表控件加载所有的作者，分类，出版社）
	void AddToListBookItem(vector<BookItem>& tvb, bool flag);
	//向列表控件添加书籍用户已借书籍
	void AddToListLoanItem();

private slots:
	//自定义最小化、关闭、设置按钮
	void OnBtnCloseClicked();
	void OnBtnMinClicked();
	void OnBtnFreShenClicked();

	void OnBtnSearchClicked();
	void OnListBookClicked(QListWidgetItem *);//点击列表控件的响应
	void OnCurrentIndexChanged(int);//右上角列表控件的响应函数
	//书籍的筛选(作者、分类、出版社)和排序（库存和出版日期）响应
	void BookDeal();
	void OnCmbKuCunIndexChanged(int);
	void OnCmbDateIndexChanged(int);

private:
	vector<BookItem>listItemBook;//临时存储listBook中显示的结果共BookDeal使用
	//向列表添加书籍完成的标志（用以消除AddToListBookItem函数体中对BookDeal函数的不可控调用）
	bool addToListBookFinished;

private:
	//实现窗口可拖动
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //鼠标相对于窗体的位置
	bool isMousePressed;    //鼠标是否按下

signals://注销和退出登录的信号，1为注销2为退出登录
	void ZhuxiaoOrExit(int);
};
