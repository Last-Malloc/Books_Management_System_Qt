#include "MessageWindow.h"
#include "ListMessage.h"

MessageWindow::MessageWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	isMousePressed = false;

	ui.listWidget->setItemDelegate(new ListMessage(ui.listWidget));

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(OnBtnOKClicked()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(OnBtnCancelClicked()));
	connect(ui.btnBack, SIGNAL(clicked()), this, SLOT(OnBtnBackClicked()));

	QListWidgetItem *item;
	for (int i = 0;i < FileManage::messageData.size();++i)
	{
		item = new QListWidgetItem();
		item->setData(Qt::UserRole, GBK::ToUnicode(FileManage::messageData[i].iconName));
		item->setData(Qt::UserRole + 1, GBK::ToUnicode(FileManage::messageData[i].ID));
		item->setData(Qt::UserRole + 2, GBK::ToUnicode(FileManage::messageData[i].name));
		item->setData(Qt::UserRole + 3, GBK::ToUnicode(FileManage::messageData[i].institute));
		item->setData(Qt::UserRole + 4, GBK::ToUnicode(FileManage::messageData[i].className));
		item->setData(Qt::UserRole + 5, QString::number(FileManage::messageData[i].sex));
		ui.listWidget->addItem(item);
	}
}

MessageWindow::~MessageWindow()
{

}

void MessageWindow::OnBtnOKClicked()
{
	QList<QListWidgetItem *>tItem = ui.listWidget->selectedItems();
	if (tItem.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("您未选择任何申请，请选择！！！"));
		return;
	}

	string ID = GBK::FromUnicode((tItem[0]->data(Qt::UserRole + 1)).toString());
	UserItem t;
	//删除messageData中的记录
	for (int i = 0;i < FileManage::messageData.size();++i)
	{
		if (ID == FileManage::messageData[i].ID)
		{
			t = FileManage::messageData[i];
			FileManage::messageData.erase(FileManage::messageData.begin() + i);
			break;
		}
	}
	//写入文件
	FileManage::WriteToMessage_Txt();

	//增加userDate中的记录并写入文件
	FileManage::AddUser(t);
	
	//删除List中的行
	delete ui.listWidget->currentItem();
}

void MessageWindow::OnBtnCancelClicked()
{
	QList<QListWidgetItem *>tItem = ui.listWidget->selectedItems();
	if (tItem.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("您未选择任何申请，请选择！！！"));
		return;
	}

	string ID = GBK::FromUnicode((tItem[0]->data(Qt::UserRole + 1)).toString());
	//删除messageData中的记录
	for (int i = 0; i < FileManage::messageData.size(); ++i)
	{
		if (ID == FileManage::messageData[i].ID)
		{
			FileManage::messageData.erase(FileManage::messageData.begin() + i);
			break;
		}
	}
	//写入文件
	FileManage::WriteToMessage_Txt();

	//删除List中的行
	delete ui.listWidget->currentItem();
}

void MessageWindow::OnBtnBackClicked()
{
	accept();
}

//鼠标按下事件
void MessageWindow::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//窗体拖动事件
void MessageWindow::mouseMoveEvent(QMouseEvent *event)
{
	//若鼠标左键被按下
	if (isMousePressed == true)
	{

		//鼠标相对于屏幕的位置
		QPoint curMousePoint = event->globalPos() - mousePoint;
		//移动主窗体位置
		move(curMousePoint);
	}
	event->accept();
}

//鼠标释放事件
void MessageWindow::mouseReleaseEvent(QMouseEvent *event)
{
	//鼠标未按下
	isMousePressed = false;
	event->accept();
}