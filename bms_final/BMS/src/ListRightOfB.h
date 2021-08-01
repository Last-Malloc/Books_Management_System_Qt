#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include "FileManage.h"
#include "GBK.h"

//listRight的B状态（包含借还日期的状态）
//index.data(Qt::UserRole + 10).toString()存储传过来的当前选中的ID

class ListRightOfB : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ListRightOfB(QObject *parent);
	~ListRightOfB();

private:
	//改变单元格大小
	virtual	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//绘制单元格
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
