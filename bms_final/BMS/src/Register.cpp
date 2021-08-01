#include "Register.h"
#include <QFileDialog>
#include <QMessageBox>
#include "TipWindow.h"
#include "FileManage.h"

Register::Register(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	headName = GBK::ToUnicode("./headpor/moren.png");
	ui.checkBUser->setChecked(true);
	ui.radioSexMan->setChecked(true);
	isMousePressed = false;

	//--------------------------------------------------�źźϲ�--------------------------
	connect(this, SIGNAL(SendIconName(QString)), ui.frame, SLOT(GetIconName(QString)));
	connect(ui.btnCHead, SIGNAL(clicked()), this, SLOT(OnBtnCHeadClicked()));
	connect(ui.checkBUser, SIGNAL(stateChanged(int)), this, SLOT(OnCheckBUserElected(int)));
	connect(ui.checkBMan, SIGNAL(stateChanged(int)), this, SLOT(OnCheckBManElected(int)));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(OnBtnOKClicked()));
	connect(ui.btnCancel,SIGNAL(clicked()),this,SLOT(OnBtnCancelClicked()));

	emit SendIconName(headName);//Ĭ��ͷ��
}

Register::~Register()
{
}

void Register::OnBtnCHeadClicked()
{
	headName = QFileDialog::getOpenFileName(this,GBK::ToUnicode("ѡ��ͷ��"),GBK::ToUnicode("*.jpg;;*.png"));
	if (headName.isEmpty())
	{
		headName = GBK::ToUnicode("./headpor/moren.png");
	}
	emit SendIconName(headName);
}

void Register::OnCheckBUserElected(int)
{
	if (ui.checkBUser->isChecked())
	{
		ui.checkBMan->setChecked(false);
	} 
	else
	{
		ui.checkBMan->setChecked(true);
	}
}

void Register::OnCheckBManElected(int)
{
	if (ui.checkBMan->isChecked())
	{
		ui.checkBUser->setChecked(false);
	} 
	else
	{
		ui.checkBUser->setChecked(true);
	}
}

void Register::OnBtnOKClicked()
{
	//ʹ��FileManage����ݴ�
	string tID = GBK::FromUnicode(ui.lineID->text());
	string tPW = GBK::FromUnicode(ui.linePassWord->text());
	int tPower;
	if (ui.checkBUser->isChecked())
	{
		tPower = 0;
	} 
	else
	{
		tPower = 1;
	}
	string tName = GBK::FromUnicode(ui.lineName->text());
	int tSex;
	if (ui.radioSexMan->isChecked())
	{
		tSex = 1;
	} 
	else
	{
		tSex = 0;
	}
	string tInstitute = GBK::FromUnicode(ui.lineInstitute->text());
	string tClassName = GBK::FromUnicode(ui.lineClassName->text());
	string tIconName = GBK::FromUnicode(headName);
	string tScProt;
	if (ui.cbQuestion->currentText() == GBK::ToUnicode("�������ܱ�"))
	{
		tScProt = "";
	}
	else
	{
		tScProt = GBK::FromUnicode(ui.cbQuestion->currentText());
	}
	string tAnswer = GBK::FromUnicode(ui.lineAnswer->text());

	UserItem tUser{ tID, tPW, tPower, tName, tSex, tInstitute,tClassName, tIconName, tScProt, tAnswer };
	bool flag =  FileManage::InspectUser(tUser);
	if (flag)
	{
		if (tPower)
		{
			FileManage::AddMessage(tUser);
			TipWindow::Information_OnlyOK(GBK::ToUnicode("���ύ���룬�ȴ���߹���Ա������������"));
		} 
		else
		{
			FileManage::AddUser(tUser);
			TipWindow::Information_OnlyOK(GBK::ToUnicode("����ɹ����뷵�ص�¼�����¼������"));
		}
	}
}

void Register::OnBtnCancelClicked()
{
	reject();
}

//��갴���¼�
void Register::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//�����϶��¼�
void Register::mouseMoveEvent(QMouseEvent *event)
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
void Register::mouseReleaseEvent(QMouseEvent *event)
{
	//���δ����
	isMousePressed = false;
	event->accept();
}