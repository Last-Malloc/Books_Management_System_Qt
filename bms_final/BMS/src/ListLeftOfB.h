#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include "FileManage.h"
#include "GBK.h"

//listLeft��B״̬�������軹���ڵ�״̬��
//index.data(Qt::UserRole + 10).toString()�洢�������ĵ�ǰѡ�е�ISBN

class ListLeftOfB : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ListLeftOfB(QObject *parent);
	~ListLeftOfB();

private:
	//�ı䵥Ԫ���С
	virtual	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	//���Ƶ�Ԫ��
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
};
