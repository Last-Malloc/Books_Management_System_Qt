#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include "FileManage.h"
#include "GBK.h"

//listLeft的B状态（包含借还日期的状态）
//index.data(Qt::UserRole + 10).toString()存储传过来的当前选中的ISBN

class ListLeftOfB : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ListLeftOfB(QObject *parent);
	~ListLeftOfB();

private:
	//改变单元格大小
	virtual	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//绘制单元格
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
