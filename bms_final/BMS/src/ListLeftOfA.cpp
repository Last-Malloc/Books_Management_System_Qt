#include "ListLeftOfA.h"

ListLeftOfA::ListLeftOfA(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

ListLeftOfA::~ListLeftOfA()
{
}

QSize ListLeftOfA::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QSize size = QStyledItemDelegate::sizeHint(option, index);
	size.setHeight(100);
	return size;
}

void ListLeftOfA::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const
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
			painter->setBrush(QColor(150, 188, 53, 100));
			painter->drawRect(rect);
		}
		else
		{
			//ż������ɫ
			painter->setBrush(QColor(200, 142, 250, 100));
			painter->drawRect(rect);
		}
	}

	//����ͷ��
	QPixmap pix(index.data(Qt::UserRole).toString());
	tRect.setRect(rect.left() + 30, rect.top() + 10, 80, 80);
	painter->drawPixmap(tRect, pix);

	//����ѧ��
	str = index.data(Qt::UserRole + 1).toString();
	tRect.setRect(rect.left() + 150, rect.top() + 15, 130, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//��������
	str = index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 175, rect.top() + 60, 80, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//����ѧԺ
	str = index.data(Qt::UserRole + 3).toString() + GBK::ToUnicode("ѧԺ");
	tRect.setRect(rect.left() + 370, rect.top() + 15, 100, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//���ư༶
	str = index.data(Qt::UserRole + 4).toString();
	tRect.setRect(rect.left() + 376, rect.top() + 60, 90, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);
}
