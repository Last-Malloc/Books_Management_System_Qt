#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include "FileManage.h"
#include "GBK.h"

//listRight��A״̬���������軹���ڵ�״̬��

class ListRightOfA : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ListRightOfA(QObject *parent);
	~ListRightOfA();

private:
	//�ı䵥Ԫ���С
	virtual	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//���Ƶ�Ԫ��
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
