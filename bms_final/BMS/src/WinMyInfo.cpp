#include "WinMyInfo.h"
#include <QFileDialog>

WinMyInfo::WinMyInfo(UserItem us, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//��Ա������ʼ��
	isMousePressed = false;

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	tempUserItem = us;
	tempIconName = GBK::ToUnicode(tempUserItem.iconName);
	ui.frame->headPorName = GBK::ToUnicode(tempUserItem.iconName);
	ui.frame->update();
	
	if (tempUserItem.power == 0)
	{
		ui.label_6->setText(GBK::ToUnicode("��ͨ�û�"));
	} 
	else
	{
		if (tempUserItem.power == 1)
		{
			ui.label_6->setText(GBK::ToUnicode("��ͨ����Ա"));
		} 
		else
		{
			ui.label_6->setText(GBK::ToUnicode("��߹���Ա"));
		}
	}

	ui.label_2->setText(GBK::ToUnicode("ѧ�ţ�" + tempUserItem.ID));

	if (tempUserItem.sex)
	{
		ui.label->setText(GBK::ToUnicode("������" + tempUserItem.name + "    �Ա���"));
	} 
	else
	{
		ui.label->setText(GBK::ToUnicode("������" + tempUserItem.name + "    �Ա�Ů"));
	}
	
	ui.label_3->setText(GBK::ToUnicode(tempUserItem.institute + "                    " + tempUserItem.className));

	if (tempUserItem.scProt == "##")
	{
		ui.lineAnswer->setEnabled(false);
	} 
	else
	{
		ui.cbQuestion->setCurrentText(GBK::ToUnicode(tempUserItem.scProt));
		ui.lineAnswer->setText(GBK::ToUnicode(tempUserItem.answer));
	}

	//-------------------------------------�źźϲ�----------------------------------------	
	connect(ui.btnCHead, SIGNAL(clicked()), this, SLOT(OnBtnCHeadClicked()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(OnBtnCancelClicked()));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(OnBtnOKClicked()));
	connect(ui.cbQuestion, SIGNAL(currentTextChanged(QString)), this, SLOT(OnCbQuestionTextChanged(QString)));
}

WinMyInfo::~WinMyInfo()
{
}

void WinMyInfo::OnBtnCHeadClicked()
{
	tempIconName = QFileDialog::getOpenFileName(this, GBK::ToUnicode("ѡ��ͷ��"), GBK::ToUnicode("*.jpg;;*.png"));
	if (!(tempIconName.isEmpty()))
	{
		ui.frame->headPorName = tempIconName;
		ui.frame->update();
	}
}

void WinMyInfo::OnBtnOKClicked()
{
	bool flag = false;
	if (tempIconName != GBK::ToUnicode(tempUserItem.iconName))
	{
		flag = true;
	}

	string tempScProt;
	string tempAnswer;
	if (ui.cbQuestion->currentText() == GBK::ToUnicode("�������ܱ�"))
	{
		tempAnswer = tempScProt = "##";
		if (tempScProt != tempUserItem.scProt)
		{
			flag = true;
		}
	} 
	else
	{
		tempScProt = GBK::FromUnicode(ui.cbQuestion->currentText());
		if (tempScProt.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�ܱ����ⲻ��Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(tempScProt, "�ܱ�����"))
		{
			return;
		}

		tempAnswer = GBK::FromUnicode(ui.lineAnswer->text());
		if (tempAnswer.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("�ܱ��𰸲���Ϊ�գ�����"));
			return;
		}
		if (!IsHaveSpace(tempAnswer, "�ܱ���"))
		{
			return;
		}

		if (tempScProt != tempUserItem.scProt || tempAnswer != tempUserItem.answer)
		{
			flag = true;
		}
		if (flag)
		{
			int queRen = TipWindow::Information_OKCancel(GBK::ToUnicode("ȷ�����ĸ�����Ϣ?"));
			if (queRen)
			{
				FileManage::AlterUser(tempUserItem.ID, EleUser::iconName, GBK::FromUnicode(tempIconName));
				FileManage::AlterUser(tempUserItem.ID, EleUser::scProt, tempScProt);
				FileManage::AlterUser(tempUserItem.ID, EleUser::answer, tempAnswer);
				accept();
			}
		}
	}
}

void WinMyInfo::OnBtnCancelClicked()
{
	reject();
}

void WinMyInfo::OnCbQuestionTextChanged(QString qstr)
{
	if (qstr == GBK::ToUnicode("�������ܱ�"))
	{
		ui.lineAnswer->clear();
		ui.lineAnswer->setEnabled(false);
	}
	else
	{
		ui.lineAnswer->setEnabled(true);
	}
}

//-------------------------------------------�û�����---------------------------------------------------------
//��갴���¼�
void WinMyInfo::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//�����϶��¼�
void WinMyInfo::mouseMoveEvent(QMouseEvent *event)
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
void WinMyInfo::mouseReleaseEvent(QMouseEvent *event)
{
	//���δ����
	isMousePressed = false;
	event->accept();
}
