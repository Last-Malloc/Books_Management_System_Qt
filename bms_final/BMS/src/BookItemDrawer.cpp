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
	//目标矩形
	QRect rect = option.rect;
	//临时矩形
	QRect tRect;

	//设置字体
	QFont font(GBK::ToUnicode("黑体"), 16, QFont::Bold);
	painter->setFont(font);

	QString str;

	//绘制单元格
	if (option.state & QStyle::State_Selected)
	{
		//选中颜色
		painter->setBrush(QColor(163,190,250,150));
		painter->drawRect(rect);
		//绘制ISBN
		tRect.setRect(rect.left() + 50, rect.top() + 150, 1000, 30);
		str = GBK::ToUnicode("ISBD:") + index.data(Qt::DisplayRole).toString();
		painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);
		//绘制简介
		tRect.setRect(rect.left() + 50, rect.top() + 190, 1000, 90);
		str = GBK::ToUnicode("简介: ") + index.data(Qt::UserRole + 8).toString();
		//设置换行
		QTextOption option;
		option.setWrapMode(QTextOption::WrapAnywhere);
		
		painter->drawText(tRect, str, option);
	}
	else
	{
		if (index.row() % 2)
		{
			//奇数排颜色
			painter->setBrush(QColor(150, 188, 53, 100));
			painter->drawRect(rect);
		}
		else
		{
			//偶数排颜色
			painter->setBrush(QColor(200, 142, 250, 100));
			painter->drawRect(rect);
		}
	}
	
	//绘制头像
	QPixmap pix(index.data(Qt::UserRole + 7).toString());
	tRect.setRect(rect.left() + 25, rect.top() + 20, 90, 110);
	painter->drawPixmap(tRect, pix);

	//绘制书名
	str = index.data(Qt::UserRole).toString();
	tRect.setRect(rect.left() + 165, rect.top() + 20, 430, 30);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);

	//绘制作者和文献类型
	str = index.data(Qt::UserRole + 1).toString() + GBK::ToUnicode("  中图分类:") + index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 165, rect.top() + 60, 510, 30);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);

	//绘制出版社和出版日期
	str = index.data(Qt::UserRole + 5).toString() + "  " + index.data(Qt::UserRole + 6).toString();
	tRect.setRect(rect.left() + 165, rect.top() + 100, 510, 30);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);

	//绘制索书号
	str = GBK::ToUnicode("索书号:") + index.data(Qt::UserRole + 3).toString();
	tRect.setRect(rect.left() + 700, rect.top() + 20, 250, 50);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);

	//绘制库存容量
	str = GBK::ToUnicode("库存:") + index.data(Qt::UserRole + 4).toString();
	tRect.setRect(rect.left() + 770, rect.top() + 80, 110, 50);
	painter->drawText(tRect, Qt::AlignLeft | Qt::AlignVCenter, str);
}
