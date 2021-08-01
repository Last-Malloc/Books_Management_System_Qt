#pragma once

#include <QtGui>
#include <QListWidgetItem>
#include "ui_ManaBookItem.h"
#include "FileManage.h"

class ManaBookItem : public QWidget
{
	Q_OBJECT

public:
	ManaBookItem(QListWidgetItem *tItem, QWidget *parent = Q_NULLPTR);
	~ManaBookItem();
	Ui::ManaBookItem ui;

private slots:
	void OnToolButtonChecked();

private:

	QListWidgetItem *tempInfo;
};
