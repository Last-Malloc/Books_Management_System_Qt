#pragma once

#include <QDialog>
#include <QList>
#include "ui_MessageWindow.h"
#include "FileManage.h"

class MessageWindow : public QDialog
{
	Q_OBJECT

public:
	MessageWindow(QWidget *parent = Q_NULLPTR);
	~MessageWindow();

private:
	Ui::MessageWindow ui;

private slots:
	void OnBtnOKClicked();
	void OnBtnCancelClicked();
	void OnBtnBackClicked();

private:
	//ʵ�ִ��ڿ��϶�
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //�������ڴ����λ��
	bool isMousePressed;    //����Ƿ���
};
