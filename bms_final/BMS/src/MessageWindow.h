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
	//实现窗口可拖动
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //鼠标相对于窗体的位置
	bool isMousePressed;    //鼠标是否按下
};
