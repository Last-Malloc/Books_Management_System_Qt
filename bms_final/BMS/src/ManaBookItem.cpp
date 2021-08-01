#include "ManaBookItem.h"

ManaBookItem::ManaBookItem(QListWidgetItem *tItem, QWidget *parent)
	: tempInfo(tItem), QWidget(parent)
{
	ui.setupUi(this);
	
	ui.frameHead->headPorName = tItem->data(Qt::UserRole + 7).toString();
	ui.frameHead->update();
	ui.ISBN->setText(tItem->data(Qt::UserRole + 9).toString());
	ui.name->setText(tItem->data(Qt::UserRole).toString());
	ui.author->setText(tItem->data(Qt::UserRole + 1).toString());
	ui.category->setText(GBK::ToUnicode("分类:") + tItem->data(Qt::UserRole + 2).toString());
	ui.tableNumber->setText(GBK::ToUnicode("索书号:") + tItem->data(Qt::UserRole + 3).toString());
	ui.storageRate->setText(GBK::ToUnicode("库存:") + tItem->data(Qt::UserRole + 4).toString());
	ui.pubCompany->setText(tItem->data(Qt::UserRole + 5).toString());
	ui.pubDate->setText(tItem->data(Qt::UserRole + 6).toString());
	ui.introduction->setText(tItem->data(Qt::UserRole + 8).toString());

	connect(ui.toolButton, SIGNAL(clicked()), this, SLOT(OnToolButtonChecked()));
}

ManaBookItem::~ManaBookItem()
{
}

void ManaBookItem::OnToolButtonChecked()
{
	if (ui.toolButton->isChecked())
	{
		ui.toolButton->setIcon(QIcon(GBK::ToUnicode(":/用户界面小按钮/Resources/小按钮/选中.png")));
	}
	else
	{
		ui.toolButton->setIcon(QIcon(GBK::ToUnicode(":/用户界面小按钮/Resources/小按钮/未选中.png")));
	}
}
