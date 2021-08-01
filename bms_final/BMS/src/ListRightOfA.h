#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include "FileManage.h"
#include "GBK.h"

//listRight的A状态（不包含借还日期的状态）

class ListRightOfA : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ListRightOfA(QObject *parent);
	~ListRightOfA();

private:
	//改变单元格大小
	virtual	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//绘制单元格
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
