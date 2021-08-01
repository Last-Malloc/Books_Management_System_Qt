#include "ListRightOfA.h"

ListRightOfA::ListRightOfA(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

ListRightOfA::~ListRightOfA()
{
}


QSize ListRightOfA::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QSize size = QStyledItemDelegate::sizeHint(option, index);
	size.setHeight(100);
	return size;
}

void ListRightOfA::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	//Ŀ�����
	QRect rect = option.rect;
	//��ʱ����
	QRect tRect;

	//��������
	QFont font(GBK::ToUnicode("����"), 14, QFont::Bold);
	painter->setFont(font);

	QString str;

	//���Ƶ�Ԫ��
	if (option.state & QStyle::State_Selected)
	{
		//ѡ����ɫ
		painter->setBrush(QColor(0, 122, 204, 150));
		painter->drawRect(rect);
	}
	else
	{
		if (index.row() % 2)
		{
			//��������ɫ
			painter->setBrush(QColor(150, 150, 53, 100));
			painter->drawRect(rect);
		}
		else
		{
			//ż������ɫ
			painter->setBrush(QColor(200, 180, 250, 100));
			painter->drawRect(rect);
		}
	}

	//����ͼƬ
	QPixmap pix(index.data(Qt::UserRole).toString());
	tRect.setRect(rect.left() + 10, rect.top() + 10, 62, 80);
	painter->drawPixmap(tRect, pix);

	//����ISBN
	str = index.data(Qt::UserRole + 1).toString();
	tRect.setRect(rect.left() + 100, rect.top() + 15, 220, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//��������
	str = index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 100, rect.top() + 60, 210, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//��������
	str = index.data(Qt::UserRole + 3).toString();
	tRect.setRect(rect.left() + 386, rect.top() + 15, 81, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//���Ƴ�����
	str = index.data(Qt::UserRole + 4).toString();
	tRect.setRect(rect.left() + 344, rect.top() + 60, 170, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);
}

