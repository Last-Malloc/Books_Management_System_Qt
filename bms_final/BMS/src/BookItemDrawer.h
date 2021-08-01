#pragma once

#include <QStyledItemDelegate>
#include <QtGui>
#include "GBK.h"
#include <QListWidgetItem>

class BookItemDrawer : public QStyledItemDelegate
{
	Q_OBJECT

public:
	BookItemDrawer(QObject *parent);
	~BookItemDrawer();

private:
	//绘制单元格
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
