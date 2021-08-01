#include "ListRightOfB.h"

ListRightOfB::ListRightOfB(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

ListRightOfB::~ListRightOfB()
{
}

QSize ListRightOfB::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QSize size = QStyledItemDelegate::sizeHint(option, index);
	size.setHeight(100);
	return size;
}

void ListRightOfB::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	//Ŀ�����
	QRect rect = option.rect;
	//��ʱ����
	QRect tRect;

	//��������
	QFont font(GBK::ToUnicode("����"), 14, QFont::Bold);
	painter->setFont(font);

	QString str;

	string ISBN = GBK::FromUnicode(index.data(Qt::UserRole + 1).toString());
	string ID = GBK::FromUnicode(index.data(Qt::UserRole + 10).toString());

	LoanItem *tLoan = FileManage::SelectLoan(ID, ISBN);

	string borrow = tLoan->loanDate;
	string retu = tLoan->retnDate;

	//��������
	int overDate = NowExceedInputDate(retu);

	//���Ƶ�Ԫ��
	if (option.state & QStyle::State_Selected)
	{
		//ѡ����ɫ
		painter->setBrush(QColor(0, 122, 204, 150));
		painter->drawRect(rect);
	}
	else
	{
		if (overDate > 0)
		{
			//������ɫ
			painter->setBrush(QColor(240, 80, 20, 150));
			painter->drawRect(rect);
		}
		else
		{
			//��������ɫ
			painter->setBrush(QColor(220, 240, 170, 150));
			painter->drawRect(rect);
		}
	}

	//����ͷ��
	QPixmap pix(index.data(Qt::UserRole).toString());
	tRect.setRect(rect.left() + 10, rect.top() + 10, 62, 80);
	painter->drawPixmap(tRect, pix);

	//����ISBN
	str = index.data(Qt::UserRole + 1).toString();
	tRect.setRect(rect.left() + 80, rect.top() + 15, 220, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//��������
	str = index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 80, rect.top() + 60, 210, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//���ƽ�������
	str = GBK::ToUnicode("��:") + GBK::ToUnicode(borrow);
	tRect.setRect(rect.left() + 300, rect.top() + 15, 160, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//���ƻ�������
	str = GBK::ToUnicode("��:") + GBK::ToUnicode(retu);
	tRect.setRect(rect.left() + 300, rect.top() + 60, 160, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//�����Ƿ������
	if (tLoan->isRenew == 1)
	{
		str = GBK::ToUnicode("������");
	}
	else
	{
		str = GBK::ToUnicode("δ����");
	}
	tRect.setRect(rect.left() + 465, rect.top() + 35, 76, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//������������
	if (overDate > 0)
	{
		str = GBK::ToUnicode("��:") + QString::number(overDate);
		tRect.setRect(rect.left() + 465, rect.top() + 67, 76, 30);
		painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);
	}
}