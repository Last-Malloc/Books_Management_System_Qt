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
	QString tempIconName;//临时存储更改后的头像名，点确认后再保存修改

private slots:
	void OnBtnCHeadClicked();
	void OnBtnOKClicked();
	void OnBtnCancelClicked();
	void OnCbQuestionTextChanged(QString);

private:
	//实现窗口可拖动
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //鼠标相对于窗体的位置
	bool isMousePressed;    //鼠标是否按下
};
