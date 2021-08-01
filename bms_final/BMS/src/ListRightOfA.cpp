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
	//目标矩形
	QRect rect = option.rect;
	//临时矩形
	QRect tRect;

	//设置字体
	QFont font(GBK::ToUnicode("黑体"), 14, QFont::Bold);
	painter->setFont(font);

	QString str;

	//绘制单元格
	if (option.state & QStyle::State_Selected)
	{
		//选中颜色
		painter->setBrush(QColor(0, 122, 204, 150));
		painter->drawRect(rect);
	}
	else
	{
		if (index.row() % 2)
		{
			//奇数排颜色
			painter->setBrush(QColor(150, 150, 53, 100));
			painter->drawRect(rect);
		}
		else
		{
			//偶数排颜色
			painter->setBrush(QColor(200, 180, 250, 100));
			painter->drawRect(rect);
		}
	}

	//绘制图片
	QPixmap pix(index.data(Qt::UserRole).toString());
	tRect.setRect(rect.left() + 10, rect.top() + 10, 62, 80);
	painter->drawPixmap(tRect, pix);

	//绘制ISBN
	str = index.data(Qt::UserRole + 1).toString();
	tRect.setRect(rect.left() + 100, rect.top() + 15, 220, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制书名
	str = index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 100, rect.top() + 60, 210, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制作者
	str = index.data(Qt::UserRole + 3).toString();
	tRect.setRect(rect.left() + 386, rect.top() + 15, 81, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制出版社
	str = index.data(Qt::UserRole + 4).toString();
	tRect.setRect(rect.left() + 344, rect.top() + 60, 170, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);
}

