#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include "GBK.h"

class ListMessage : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ListMessage(QObject *parent);
	~ListMessage();

private:
	//改变单元格大小
	virtual	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//绘制单元格
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
