#include "ListMessage.h"

ListMessage::ListMessage(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

ListMessage::~ListMessage()
{
}

QSize ListMessage::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QSize size = QStyledItemDelegate::sizeHint(option, index);
	size.setHeight(100);
	return size;
}

void ListMessage::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const
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
		painter->setBrush(QColor(163, 190, 250, 200));
		painter->drawRect(rect);
	}
	else
	{
		if (index.row() % 2)
		{
			//��������ɫ
			painter->setBrush(QColor(246, 242, 84, 150));
			painter->drawRect(rect);
		}
		else
		{
			//ż������ɫ
			painter->setBrush(QColor(200, 142, 250, 150));
			painter->drawRect(rect);
		}
	}

	//����ͷ��
	QPixmap pix(index.data(Qt::UserRole).toString());
	tRect.setRect(rect.left() + 20, rect.top() + 10, 63, 80);
	painter->drawPixmap(tRect, pix);

	//����ѧ��
	str = index.data(Qt::UserRole + 1).toString();
	tRect.setRect(rect.left() + 110, rect.top() + 40, 140, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//��������
	str = index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 270, rect.top() + 40, 76, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//����ѧԺ
	str = index.data(Qt::UserRole + 3).toString() + GBK::ToUnicode("ѧԺ");
	tRect.setRect(rect.left() + 420, rect.top() + 40, 110, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//���ư༶
	str = index.data(Qt::UserRole + 4).toString();
	tRect.setRect(rect.left() + 550, rect.top() + 40, 100, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//�����Ա�
	str = index.data(Qt::UserRole + 5).toString();
	if (str == GBK::ToUnicode("1"))
	{
		str = GBK::ToUnicode("��");
	}
	else
	{
		str = GBK::ToUnicode("Ů");
	}
	tRect.setRect(rect.left() + 370, rect.top() + 40, 30, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);
}