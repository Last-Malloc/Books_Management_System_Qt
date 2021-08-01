#pragma once

#include <QWidget>
#include <QtGui>
#include <QListWidgetItem>
#include "ui_MyLoanItem.h"
#include "FileManage.h"

class MyLoanItem : public QWidget
{
	Q_OBJECT

public:
	MyLoanItem(QListWidgetItem *tItem, LoanItem *tLoanItem, QWidget *parent = Q_NULLPTR);
	~MyLoanItem();

private slots:
	void OnXuJieClicked();

private:
	Ui::MyLoanItem ui;

	QListWidgetItem *tItem;
	LoanItem* tLoanItem;

	virtual void paintEvent(QPaintEvent *event);
};