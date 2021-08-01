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

	//��ݼ�
	void keyPressEvent(QKeyEvent *event);

private:
	Ui::UserInterface ui;

public:
	//���б�ؼ�����鼮������flagΪtrueʱ���б�ؼ��������е����ߣ����࣬�����磩
	void AddToListBookItem(vector<BookItem>& tvb, bool flag);
	//���б�ؼ�����鼮�û��ѽ��鼮
	void AddToListLoanItem();

private slots:
	//�Զ�����С�����رա����ð�ť
	void OnBtnCloseClicked();
	void OnBtnMinClicked();
	void OnBtnFreShenClicked();

	void OnBtnSearchClicked();
	void OnListBookClicked(QListWidgetItem *);//����б�ؼ�����Ӧ
	void OnCurrentIndexChanged(int);//���Ͻ��б�ؼ�����Ӧ����
	//�鼮��ɸѡ(���ߡ����ࡢ������)�����򣨿��ͳ������ڣ���Ӧ
	void BookDeal();
	void OnCmbKuCunIndexChanged(int);
	void OnCmbDateIndexChanged(int);

private:
	vector<BookItem>listItemBook;//��ʱ�洢listBook����ʾ�Ľ����BookDealʹ��
	//���б�����鼮��ɵı�־����������AddToListBookItem�������ж�BookDeal�����Ĳ��ɿص��ã�
	bool addToListBookFinished;

private:
	//ʵ�ִ��ڿ��϶�
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //�������ڴ����λ��
	bool isMousePressed;    //����Ƿ���

signals://ע�����˳���¼���źţ�1Ϊע��2Ϊ�˳���¼
	void ZhuxiaoOrExit(int);
};
