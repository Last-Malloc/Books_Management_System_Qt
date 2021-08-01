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
	void OnOKClicked();//ȷ����ť
	void OnBackClicked();//���ذ�ť
	void OnLgIDEditChanged(QString);//�˺������仯��Ӧ

public:
	Ui::FindPassword ui;

	UserItem* tUser;

	//��������״̬λ�������ı�ȷ����ť����Ӧ
	int czFlag;

	//ʵ�ִ��ڿ��϶�
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //�������ڴ����λ��
	bool isMousePressed;    //����Ƿ���
};
