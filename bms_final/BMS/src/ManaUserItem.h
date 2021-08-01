#pragma once

#include <QtGui>
#include <QListWidgetItem>
#include "ui_ManaUserItem.h"
#include "GBK.h"

class ManaUserItem : public QWidget
{
	Q_OBJECT

public:
	ManaUserItem(QListWidgetItem *tItem, QWidget *parent = Q_NULLPTR);
	~ManaUserItem();
	Ui::ManaUserItem ui;

private slots:
	void OnToolButtonChecked();

private:

	QListWidgetItem *tempUserInfo;
};
