#pragma once

/*����Ϊ��¼����*/

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
	void SendIconName(QString);//����ͷ��

private:
	Ui::BMSClass ui;

//----------------------------------------------------------------------------------------------------

private slots:
	//��Ӧ����
	void OnLgIDEditChanged(QString);//�˺������仯��Ӧ
	void OnLgOKClicked();//��¼��ť��Ӧ
	void OnLgRegisterClicked();//ע���˺Ű�ť��Ӧ
	void OnLgFindPWClicked();//�һ����밴ť��Ӧ
	void OnRemberPWElected(int);//��ס���밴ť��Ӧ
	void OnLgShowPWChanged();//��ʾ/����������Ӧ
	void OnZhuXiaoExit(int);//�û�����ע��/�˳�����Ӧ����

private:
	void AddItemToLgID();//��ID�������ӷ��ʹ����˻�

//---------------------------------------��־λ--------------------------
	int rememberFlag;//��ס����ı�־
	int showPwFlag;//��ʾ����Ϊ1

//---------------------------------------�洢��ǰID����ӦԪ����--------------------------
	UserItem *tempUser;
	RecentItem *tempRecent;
	//��ʱ�洢tempRecent��tempUser����Ա�ṹ��ID�Է�ֹ��ָ��ָ������ݱ�������ʽ�ı�
	string ttUser,ttRecent;
	
//---------------------------------------�Ӵ���--------------------------
	MgInterface *mgJiemian;//����Ա����
	UserInterface *userJiemian;//�û�����
	FindPassword *findPW;//�һ��������
	Register *regt;//�û�ע�����

//-----------------------------------------�û�����--------------------------------------------------------	
private slots:
	//�Զ�����С�����رա����ð�ť
	void OnBtnCloseClicked();
	void OnBtnMinClicked();
	void OnBtnSetClicked();
private:
	//ʵ�ִ��ڿ��϶�
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //�������ڴ����λ��
	bool isMousePressed;    //����Ƿ���
};
