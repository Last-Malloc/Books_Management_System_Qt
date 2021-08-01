#include "ManaUserItem.h"

ManaUserItem::ManaUserItem(QListWidgetItem *tItem, QWidget *parent)
	: tempUserInfo(tItem), QWidget(parent)
{
	ui.setupUi(this);

	ui.frameHead->headPorName = tItem->data(Qt::UserRole).toString();
	ui.frameHead->update();
	ui.ID->setText(tItem->data(Qt::UserRole + 1).toString());
	
	if (GBK::FromUnicode(tItem->data(Qt::UserRole + 2).toString()) == "1")
	{
		ui.power->setText(GBK::ToUnicode("����Ա"));
	} 
	else
	{
		ui.power->setText(GBK::ToUnicode("��ͨ�û�"));
	}

	ui.name->setText(tItem->data(Qt::UserRole + 3).toString());
	if (GBK::FromUnicode(tItem->data(Qt::UserRole + 4).toString()) == "1")
	{
		ui.sex->setText(GBK::ToUnicode("��"));
	} 
	else
	{
		ui.sex->setText(GBK::ToUnicode("Ů"));
	}
	ui.institute->setText(tItem->data(Qt::UserRole + 5).toString() + GBK::ToUnicode("ѧԺ"));
	ui.className->setText(tItem->data(Qt::UserRole + 6).toString());

	connect(ui.toolButton, SIGNAL(clicked()), this, SLOT(OnToolButtonChecked()));
}

ManaUserItem::~ManaUserItem()
{
}

void ManaUserItem::OnToolButtonChecked()
{
	if (ui.toolButton->isChecked())
	{
		ui.toolButton->setIcon(QIcon(GBK::ToUnicode(":/�û�����С��ť/Resources/С��ť/ѡ��.png")));
	}
	else
	{
		ui.toolButton->setIcon(QIcon(GBK::ToUnicode(":/�û�����С��ť/Resources/С��ť/δѡ��.png")));
	}
}
