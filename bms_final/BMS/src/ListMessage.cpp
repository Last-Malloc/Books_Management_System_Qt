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
		painter->setBrush(QColor(163, 190, 250, 200));
		painter->drawRect(rect);
	}
	else
	{
		if (index.row() % 2)
		{
			//奇数排颜色
			painter->setBrush(QColor(246, 242, 84, 150));
			painter->drawRect(rect);
		}
		else
		{
			//偶数排颜色
			painter->setBrush(QColor(200, 142, 250, 150));
			painter->drawRect(rect);
		}
	}

	//绘制头像
	QPixmap pix(index.data(Qt::UserRole).toString());
	tRect.setRect(rect.left() + 20, rect.top() + 10, 63, 80);
	painter->drawPixmap(tRect, pix);

	//绘制学号
	str = index.data(Qt::UserRole + 1).toString();
	tRect.setRect(rect.left() + 110, rect.top() + 40, 140, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制姓名
	str = index.data(Qt::UserRole + 2).toString();
	tRect.setRect(rect.left() + 270, rect.top() + 40, 76, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制学院
	str = index.data(Qt::UserRole + 3).toString() + GBK::ToUnicode("学院");
	tRect.setRect(rect.left() + 420, rect.top() + 40, 110, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制班级
	str = index.data(Qt::UserRole + 4).toString();
	tRect.setRect(rect.left() + 550, rect.top() + 40, 100, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);

	//绘制性别
	str = index.data(Qt::UserRole + 5).toString();
	if (str == GBK::ToUnicode("1"))
	{
		str = GBK::ToUnicode("男");
	}
	else
	{
		str = GBK::ToUnicode("女");
	}
	tRect.setRect(rect.left() + 370, rect.top() + 40, 30, 30);
	painter->drawText(tRect, Qt::AlignHCenter | Qt::AlignVCenter, str);
}