#pragma once

#include <QFrame>
#include <QPushButton>
#include <QToolButton>
#include <QPainter>
#include "GBK.h"
#include "FileManage.h"

class MessageButton : public QToolButton
{
	Q_OBJECT

public:
	MessageButton(QWidget *parent);
	~MessageButton();

	void paintEvent(QPaintEvent *event);
};
