#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include "GBK.h"

//listLeft��A״̬���������軹���ڵ�״̬��

class ListLeftOfA : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ListLeftOfA(QObject *parent);
	~ListLeftOfA();

private:
	//�ı䵥Ԫ���С
	virtual	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//���Ƶ�Ԫ��
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
