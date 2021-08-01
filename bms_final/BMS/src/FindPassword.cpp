#include "FindPassword.h"
#include "TipWindow.h"

FindPassword::FindPassword(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	//��ʼ��
	ui.radioZH->setChecked(true);
	tUser = nullptr;
	czFlag = 0;
	isMousePressed = false;

	connect(ui.lineID, SIGNAL(textChanged(QString)), this, SLOT(OnLgIDEditChanged(QString)));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(OnOKClicked()));
	connect(ui.btnBack, SIGNAL(clicked()), this, SLOT(OnBackClicked()));
}

FindPassword::~FindPassword()
{
}

void FindPassword::OnLgIDEditChanged(QString temp)
{
	ui.lineAnswer->setEnabled(true);
	ui.label_3->clear();
	if (temp.size() == 10)
	{
		tUser = FileManage::SelectUser(GBK::FromUnicode(temp));
		if (tUser)
		{
			if (tUser->scProt == "##")
			{
				ui.label_3->setText(GBK::ToUnicode("��δ�����ܱ������ڹ���Ա���������룡����"));
				ui.lineAnswer->setEnabled(false);
			} 
			else
			{
				ui.label_3->setText(GBK::ToUnicode(tUser->scProt));
			}
		} 
		else
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("���˺Ų����ڣ����������룡����"));
		}
	}
}

void FindPassword::OnOKClicked()
{
	if (czFlag == 0)
	{
		if (ui.lineID->text().size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�û�������Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(GBK::FromUnicode(ui.lineID->text()), "�û���"))
		{
			return;
		}
		if (tUser == nullptr)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�û��������ڣ�����"));
			return;
		}
		if (ui.lineAnswer->text().size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�ܱ�����Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(GBK::FromUnicode(ui.lineAnswer->text()), "�ܱ�"))
		{
			return;
		}
	}
	if (czFlag)
	{
		if (ui.lineID->text().isEmpty())
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�����벻��Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(GBK::FromUnicode(ui.lineID->text()), "������"))
		{
			return;
		}
		if (ui.lineAnswer->text().isEmpty())
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("ȷ�����벻��Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(GBK::FromUnicode(ui.lineAnswer->text()), "ȷ������"))
		{
			return;
		}
		if (ui.lineID->text() != ui.lineAnswer->text())
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�������벻һ�£����������룡����"));
			return;
		}
		if (FileManage::AlterUser(tUser->ID, EleUser::password, GBK::FromUnicode(ui.lineID->text())))
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�����޸ĳɹ���������Ϊ") + ui.lineID->text());
		}
		return;
	}
	if (tUser != nullptr)
	{
		if (tUser->scProt != "##")
		{
			if (tUser->answer == GBK::FromUnicode(ui.lineAnswer->text()))
			{
				if (ui.radioZH->isChecked())
				{
					TipWindow::Information_OnlyOK(GBK::ToUnicode("��������Ϊ��" + tUser->password));
				} 
				else
				{
					czFlag = 1;
					ui.label_3->hide();
					ui.label->setText(GBK::ToUnicode("������"));
					ui.label->move(70, 60);
					ui.label_2->setText(GBK::ToUnicode("ȷ������"));
					ui.label_2->move(40, 120);
					ui.lineID->setPlaceholderText(GBK::ToUnicode("������������"));
					ui.lineID->move(150, 60);
					ui.lineAnswer->setPlaceholderText(GBK::ToUnicode("����������������"));
					ui.lineAnswer->move(150, 120);
					ui.radioCZ->hide();
					ui.radioZH->hide();
					ui.btnOK->move(140, 200);
					ui.lineID->clear();
					ui.lineAnswer->clear();
				}
			} 
			else
			{
				TipWindow::Information_OnlyOK(GBK::ToUnicode("�ܱ��������������룡����"));
			}
		}
	}
}

void FindPassword::OnBackClicked()
{
	accept();
}

//��갴���¼�
void FindPassword::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//�����϶��¼�
void FindPassword::mouseMoveEvent(QMouseEvent *event)
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
void FindPassword::mouseReleaseEvent(QMouseEvent *event)
{
	//���δ����
	isMousePressed = false;
	event->accept();
}