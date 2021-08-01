#pragma once

#include <QtGui>
#include "ui_WinMyInfo.h"
#include "FileManage.h"
#include "TipWindow.h"

class WinMyInfo : public QDialog
{
	Q_OBJECT

public:
	WinMyInfo(UserItem us, QWidget *parent = Q_NULLPTR);
	~WinMyInfo();

private:
	Ui::WinMyInfo ui;
	UserItem tempUserItem;
	QString tempIconName;//��ʱ�洢���ĺ��ͷ��������ȷ�Ϻ��ٱ����޸�

private slots:
	void OnBtnCHeadClicked();
	void OnBtnOKClicked();
	void OnBtnCancelClicked();
	void OnCbQuestionTextChanged(QString);

private:
	//ʵ�ִ��ڿ��϶�
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //�������ڴ����λ��
	bool isMousePressed;    //����Ƿ���
};
