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
	QPixmap pix(index.data(Qt::UserRole).toString());
	tRect.setRect(rect.left() + 30, rect.top() + 10, 80, 80);
	painter->drawPixmap(tRect, pix);

	//绘制学号
	str = index.data(Qt::UserRole + 1).toString();
	tRect.setRect(rect.left() + 150, rect.top() + 15, 130, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制姓名
	str = index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 175, rect.top() + 60, 80, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制学院
	str = index.data(Qt::UserRole + 3).toString() + GBK::ToUnicode("学院");
	tRect.setRect(rect.left() + 370, rect.top() + 15, 100, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制班级
	str = index.data(Qt::UserRole + 4).toString();
	tRect.setRect(rect.left() + 376, rect.top() + 60, 90, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);
}
