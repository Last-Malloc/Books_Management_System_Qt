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
	//�ı䵥Ԫ���С
	virtual	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//���Ƶ�Ԫ��
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
