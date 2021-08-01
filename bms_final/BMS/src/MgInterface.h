#pragma once

#include <QtGui>
#include <set>
#include <QFileDialog>
#include "ui_MgInterface.h"
#include "Manager.h"
#include "FileManage.h"
#include "WinMyInfo.h"
#include "FindPassword.h"
#include "TipWindow.h"
#include "ManaBookItem.h"
#include "ManaUserItem.h"
#include "ListLeftOfA.h"
#include "ListLeftOfB.h"
#include "ListRightOfA.h"
#include "ListRightOfB.h"
#include "MessageWindow.h"

using std::set;

class MgInterface : public QWidget, public Manager
{
	Q_OBJECT

	//------------------------------------主页面--------------------------------------
public:
	MgInterface(UserItem us, QWidget *parent = Q_NULLPTR);
	~MgInterface();

	//快捷键
	void keyPressEvent(QKeyEvent *event);

signals:
	//注销和退出登录的信号，1为注销2为退出登录
	void ZhuxiaoOrExit(int);

private slots:
	//右上角列表控件的响应函数
	void OnCurrentIndexChanged(int);
	void OnBtnMessageClicked();
	void OnBtnFreShenClicked();

	//-----------------------------------借阅管理界面---------------------------------

private slots:
	//combobox功能选择框
	void OnBtnJYueOrderIndexChanged(int);
	//左侧用户列表的填充
	void AddToListLeft(vector<UserItem>vu, string tIsbn ="");
	//右侧书籍列表的填充
	void AddToListRight(vector<BookItem>vb, string tId = "");
	//确定按钮
	void OnBtnJYueButtonClicked();
	//ID框的回车响应
	void OnJYueLIneIDReturnPressed();
	//ISBN框的回车响应
	void OnJYueLineISBNReturnPressed();
	//点击ListLeft的Item的响应
	void OnListLeftClicked(QListWidgetItem *);
	//点击ListRight的Item的响应
	void OnListRightClicked(QListWidgetItem *);

	//-----------------------------------图书管理的修改/下架页面----------------------
	//(重要)书籍信息直接来自FileManage::bookData
private slots:
	//图书修改页面隐藏按钮响应函数
	void OnBtnBooKBarHideClicked();
	//书籍查找按钮
	void OnBtnSearchClicked();
	//点击列表控件的响应
	void OnListBookClicked(QListWidgetItem *);
	//排序组合框的互斥
	void OnCmbKuCunIndexChanged(int);
	void OnCmbDateIndexChanged(int);
	//全选按钮
	void OnBtnBkBarSelectClicked();
	//下架按钮
	void OnBtnBkBarDeleteClicked();
	void BookDeal();
	//修改按钮
	void OnBtnBkBarAlterClicked();
	void OnBntBkBarChgeHeadClicked();

public:
	//向列表控件添加书籍（并且flag为true时向列表控件加载所有的作者，分类，出版社）
	void AddToListBookItem(vector<BookItem>& tvb, bool flag);

private:
	//临时存储listBook中显示的结果共BookDeal使用
	vector<BookItem>listItemBook;
	
	bool bookSelectAll;//书籍是否全选的标志
	//向列表添加书籍完成的标志（用以消除AddToListBookItem函数体中对BookDeal函数的不可控调用）
	bool addToListBookFinished;

	//-----------------------------------图书管理的上架页面--------------------------------

private slots:
	//选择文件按钮
	void OnBtnSJiaChooseFileClicked();
	//确定按钮
	void OnBtnSJiaOKClicked();
	//更换图片按钮
	void OnBtnSJiaChgeHeadClicked();

	//-----------------------------------用户管理页面----------------------------------------------
private slots:
	//隐藏按钮
	void OnBtnUserBarHideClicked();
	//用户查找按钮
	void OnBtnUserBarSearchClicked();
	//点击列表控件的响应
	void OnListUserClicked(QListWidgetItem *);
	void UserDeal();
	//重置密码按钮
	void OnBtnUserBarResetPW();
	//全选/全不选按钮
	void OnBtnUserBarSelectAll();
	//删除按钮
	void OnBtnUserBarDelete();
	//确定按钮
	void OnBtnUserBarOKClicked();

private:
	//临时存储listUser中显示的结果共供UserDeal使用
	vector<UserItem>listItemUser;

	bool userSelectAll;//用户是否全选的标志
	//向列表添加用户完成的标志（用以消除AddToListUserItem函数体中对UserDeal函数的不可控调用）
	bool addToListUserFinished;

public:
	//向列表控件添加书籍（并且flag为true时向列表控件加载所有的作者，分类，出版社）
	//不同权限填充的数据不同
	void AddToListUserItem(vector<UserItem>& tvb, bool flag);

//----------------------------------------------------体验---------------------------------
private:
	Ui::MgInterface ui;

private slots:
	//自定义最小化、关闭、设置按钮
	void OnBtnCloseClicked();
	void OnBtnMinClicked();

private:
	//实现窗口可拖动
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //鼠标相对于窗体的位置
	bool isMousePressed;    //鼠标是否按下
};
