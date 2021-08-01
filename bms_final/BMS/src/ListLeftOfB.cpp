#include "ListLeftOfB.h"

ListLeftOfB::ListLeftOfB(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

ListLeftOfB::~ListLeftOfB()
{
}

QSize ListLeftOfB::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QSize size = QStyledItemDelegate::sizeHint(option, index);
	size.setHeight(100);
	return size;
}

void ListLeftOfB::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	//目标矩形
	QRect rect = option.rect;
	//临时矩形
	QRect tRect;

	//设置字体
	QFont font(GBK::ToUnicode("黑体"), 14, QFont::Bold);
	painter->setFont(font);

	QString str;

	string ID = GBK::FromUnicode(index.data(Qt::UserRole + 1).toString());
	string ISBN = GBK::FromUnicode(index.data(Qt::UserRole + 10).toString());

	LoanItem *tLoan = FileManage::SelectLoan(ID, ISBN);

	string borrow = tLoan->loanDate;
	string retu = tLoan->retnDate;

	//超期天数
	int overDate = NowExceedInputDate(retu);

	//绘制单元格
	if (option.state & QStyle::State_Selected)
	{
		//选中颜色
		painter->setBrush(QColor(0, 122, 204, 150));
		painter->drawRect(rect);
	}
	else
	{
		if (overDate > 0)
		{
			//逾期颜色
			painter->setBrush(QColor(240, 80, 20, 150));
			painter->drawRect(rect);
		}
		else
		{
			//不逾期颜色
			painter->setBrush(QColor(220, 240, 170, 150));
			painter->drawRect(rect);
		}
	}

	//绘制头像
	QPixmap pix(index.data(Qt::UserRole).toString());
	tRect.setRect(rect.left() + 30, rect.top() + 10, 80, 80);
	painter->drawPixmap(tRect, pix);

	//绘制学号
	str = GBK::ToUnicode(ID);
	tRect.setRect(rect.left() + 140, rect.top() + 15, 130, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制姓名
	str = index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 165, rect.top() + 60, 80, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制借书日期
	str = GBK::ToUnicode("借:") + GBK::ToUnicode(borrow);
	tRect.setRect(rect.left() + 290, rect.top() + 15, 160, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制还书日期
	str = GBK::ToUnicode("还:") + GBK::ToUnicode(retu);
	tRect.setRect(rect.left() + 290, rect.top() + 60, 160, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制是否已续借
	if (tLoan->isRenew == 1)
	{
		str = GBK::ToUnicode("已续借");
	} 
	else
	{
		str = GBK::ToUnicode("未续借");
	}
	tRect.setRect(rect.left() + 465, rect.top() + 35, 76, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制逾期天数
	if (overDate > 0)
	{
		str = GBK::ToUnicode("逾:") + QString::number(overDate);
		tRect.setRect(rect.left() + 465, rect.top() + 67, 76, 30);
		painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);
	}
}

