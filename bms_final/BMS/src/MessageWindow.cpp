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
		TipWindow::Information_OnlyOK(GBK::ToUnicode("��δѡ���κ����룬��ѡ�񣡣���"));
		return;
	}

	string ID = GBK::FromUnicode((tItem[0]->data(Qt::UserRole + 1)).toString());
	UserItem t;
	//ɾ��messageData�еļ�¼
	for (int i = 0;i < FileManage::messageData.size();++i)
	{
		if (ID == FileManage::messageData[i].ID)
		{
			t = FileManage::messageData[i];
			FileManage::messageData.erase(FileManage::messageData.begin() + i);
			break;
		}
	}
	//д���ļ�
	FileManage::WriteToMessage_Txt();

	//����userDate�еļ�¼��д���ļ�
	FileManage::AddUser(t);
	
	//ɾ��List�е���
	delete ui.listWidget->currentItem();
}

void MessageWindow::OnBtnCancelClicked()
{
	QList<QListWidgetItem *>tItem = ui.listWidget->selectedItems();
	if (tItem.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("��δѡ���κ����룬��ѡ�񣡣���"));
		return;
	}

	string ID = GBK::FromUnicode((tItem[0]->data(Qt::UserRole + 1)).toString());
	//ɾ��messageData�еļ�¼
	for (int i = 0; i < FileManage::messageData.size(); ++i)
	{
		if (ID == FileManage::messageData[i].ID)
		{
			FileManage::messageData.erase(FileManage::messageData.begin() + i);
			break;
		}
	}
	//д���ļ�
	FileManage::WriteToMessage_Txt();

	//ɾ��List�е���
	delete ui.listWidget->currentItem();
}

void MessageWindow::OnBtnBackClicked()
{
	accept();
}

//��갴���¼�
void MessageWindow::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//�����϶��¼�
void MessageWindow::mouseMoveEvent(QMouseEvent *event)
{
	//��������������
	if (isMousePressed == true)
	{

		//����������Ļ��λ��
		QPoint curMousePoint = event->globalPos() - mousePoint;
		//�ƶ�������λ��
		move(curMousePoint);
	}
	event->accept();
}

//����ͷ��¼�
void MessageWindow::mouseReleaseEvent(QMouseEvent *event)
{
	//���δ����
	isMousePressed = false;
	event->accept();
}