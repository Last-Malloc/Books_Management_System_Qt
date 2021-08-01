#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include "GBK.h"

//listLeft的A状态（不包含借还日期的状态）

class ListLeftOfA : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ListLeftOfA(QObject *parent);
	~ListLeftOfA();

private:
	//改变单元格大小
	virtual	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//绘制单元格
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
