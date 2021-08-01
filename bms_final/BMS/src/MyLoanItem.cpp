#include "MyLoanItem.h"
#include "myTimeDeal.h"

MyLoanItem::MyLoanItem(QListWidgetItem *tItem, LoanItem *tLoanItem, QWidget *parent)
	: QWidget(parent),tItem(tItem),tLoanItem(tLoanItem)
{
	ui.setupUi(this);

	//��ʼ���ؼ�
	ui.frameHead->headPorName = tItem->data(Qt::UserRole).toString();
	ui.frameHead->update();
	ui.labelName->setText(tItem->data(Qt::UserRole + 1).toString());
	ui.labelISBN->setText(tItem->data(Qt::UserRole + 2).toString());
	ui.labelJie->setText(tItem->data(Qt::UserRole + 3).toString());
	ui.labelHuan->setText(tItem->data(Qt::UserRole + 4).toString());
	if (tItem->data(Qt::UserRole + 5).toString() == GBK::ToUnicode("1"))
	{
		ui.labelXuJie->setText(GBK::ToUnicode("������"));
		ui.btnXuJie->hide();
	} 
	else
	{
		ui.labelXuJie->setText(GBK::ToUnicode("δ����"));
	}

	connect(ui.btnXuJie, SIGNAL(clicked()), this, SLOT(OnXuJieClicked()));
}

MyLoanItem::~MyLoanItem()
{
}

void MyLoanItem::OnXuJieClicked()
{
	//��ʾ�ϵĸı�
	ui.btnXuJie->hide();
	ui.labelXuJie->setText(GBK::ToUnicode("������"));
	QString qstr = ui.labelHuan->text();
	string str = GBK::FromUnicode(qstr);
	qstr = GBK::ToUnicode(MyCalculate(str));
	ui.labelHuan->setText(qstr);
	//�����ϵĸı� �ṹΪtxt -> FileManage->User��myLoan
	string Id = GBK::FromUnicode(tItem->data(Qt::UserRole + 10).toString());
	string Isbn = GBK::FromUnicode(tItem->data(Qt::UserRole + 2).toString());
	FileManage::AlterLoan(Id, Isbn, EleLoan::retnDate, GBK::FromUnicode(qstr));
	FileManage::AlterLoan(Id, Isbn, EleLoan::isRenew, "1");
	
	tLoanItem->retnDate = GBK::FromUnicode(qstr);
	tLoanItem->isRenew = 1;
}

void MyLoanItem::paintEvent(QPaintEvent *event)
{
	QPainter myPen(this);
	if (CompareDate(GBK::FromUnicode(tItem->data(Qt::UserRole + 4).toString()), GetNowTime()))
	{
		//û������
		myPen.setBrush(QBrush(QColor(220, 240, 170, 150)));
		myPen.drawRect(QRect(0, 0, this->width(), this->height()));
	} 
	else
	{
		//����
		ui.btnXuJie->hide();
		myPen.setBrush(QBrush(QColor(240, 80, 20, 150)));
		myPen.drawRect(QRect(0, 0, this->width(), this->height()));

		QRect target(880, 65, 190, 50);
		myPen.setPen(Qt::white);
		QFont font(GBK::ToUnicode("����"), 16, QFont::Bold);
		myPen.setFont(font);
		int overDay = NowExceedInputDate(GBK::FromUnicode(tItem->data(Qt::UserRole + 4).toString()));
		QString qstr = GBK::ToUnicode("�����ڣ�") + QString::number(overDay) + GBK::ToUnicode("��");
		myPen.drawText(target, qstr);
	}

}
