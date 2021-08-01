#include "BookItemDrawer.h"

BookItemDrawer::BookItemDrawer(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

BookItemDrawer::~BookItemDrawer()
{
}

void BookItemDrawer::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	//Ŀ�����
	QRect rect = option.rect;
	//��ʱ����
	QRect tRect;

	//��������
	QFont font(GBK::ToUnicode("����"), 16, QFont::Bold);
	painter->setFont(font);

	QString str;

	//���Ƶ�Ԫ��
	if (option.state & QStyle::State_Selected)
	{
		//ѡ����ɫ
		painter->setBrush(QColor(163,190,250,150));
		painter->drawRect(rect);
		//����ISBN
		tRect.setRect(rect.left() + 50, rect.top() + 150, 1000, 30);
		str = GBK::ToUnicode("ISBD:") + index.data(Qt::DisplayRole).toString();
		painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);
		//���Ƽ��
		tRect.setRect(rect.left() + 50, rect.top() + 190, 1000, 90);
		str = GBK::ToUnicode("���: ") + index.data(Qt::UserRole + 8).toString();
		//���û���
		QTextOption option;
		option.setWrapMode(QTextOption::WrapAnywhere);
		
		painter->drawText(tRect, str, option);
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
	QPixmap pix(index.data(Qt::UserRole + 7).toString());
	tRect.setRect(rect.left() + 25, rect.top() + 20, 90, 110);
	painter->drawPixmap(tRect, pix);

	//��������
	str = index.data(Qt::UserRole).toString();
	tRect.setRect(rect.left() + 165, rect.top() + 20, 430, 30);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);

	//�������ߺ���������
	str = index.data(Qt::UserRole + 1).toString() + GBK::ToUnicode("  ��ͼ����:") + index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 165, rect.top() + 60, 510, 30);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);

	//���Ƴ�����ͳ�������
	str = index.data(Qt::UserRole + 5).toString() + "  " + index.data(Qt::UserRole + 6).toString();
	tRect.setRect(rect.left() + 165, rect.top() + 100, 510, 30);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);

	//���������
	str = GBK::ToUnicode("�����:") + index.data(Qt::UserRole + 3).toString();
	tRect.setRect(rect.left() + 700, rect.top() + 20, 250, 50);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);

	//���ƿ������
	str = GBK::ToUnicode("���:") + index.data(Qt::UserRole + 4).toString();
	tRect.setRect(rect.left() + 770, rect.top() + 80, 110, 50);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);
}
