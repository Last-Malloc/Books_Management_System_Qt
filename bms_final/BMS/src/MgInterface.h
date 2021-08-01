#pragma once

#include <QtGui>
#include <set>
#include <QFileDialog>
#include "ui_MgInterface.h"
#include "Manager.h"
#include "FileManage.h"
#include "WinMyInfo.h"
#include "FindPassword.h"
#include "TipWindow.h"
#include "ManaBookItem.h"
#include "ManaUserItem.h"
#include "ListLeftOfA.h"
#include "ListLeftOfB.h"
#include "ListRightOfA.h"
#include "ListRightOfB.h"
#include "MessageWindow.h"

using std::set;

class MgInterface : public QWidget, public Manager
{
	Q_OBJECT

	//------------------------------------��ҳ��--------------------------------------
public:
	MgInterface(UserItem us, QWidget *parent = Q_NULLPTR);
	~MgInterface();

	//��ݼ�
	void keyPressEvent(QKeyEvent *event);

signals:
	//ע�����˳���¼���źţ�1Ϊע��2Ϊ�˳���¼
	void ZhuxiaoOrExit(int);

private slots:
	//���Ͻ��б�ؼ�����Ӧ����
	void OnCurrentIndexChanged(int);
	void OnBtnMessageClicked();
	void OnBtnFreShenClicked();

	//-----------------------------------���Ĺ������---------------------------------

private slots:
	//combobox����ѡ���
	void OnBtnJYueOrderIndexChanged(int);
	//����û��б�����
	void AddToListLeft(vector<UserItem>vu, string tIsbn ="");
	//�Ҳ��鼮�б�����
	void AddToListRight(vector<BookItem>vb, string tId = "");
	//ȷ����ť
	void OnBtnJYueButtonClicked();
	//ID��Ļس���Ӧ
	void OnJYueLIneIDReturnPressed();
	//ISBN��Ļس���Ӧ
	void OnJYueLineISBNReturnPressed();
	//���ListLeft��Item����Ӧ
	void OnListLeftClicked(QListWidgetItem *);
	//���ListRight��Item����Ӧ
	void OnListRightClicked(QListWidgetItem *);

	//-----------------------------------ͼ�������޸�/�¼�ҳ��----------------------
	//(��Ҫ)�鼮��Ϣֱ������FileManage::bookData
private slots:
	//ͼ���޸�ҳ�����ذ�ť��Ӧ����
	void OnBtnBooKBarHideClicked();
	//�鼮���Ұ�ť
	void OnBtnSearchClicked();
	//����б�ؼ�����Ӧ
	void OnListBookClicked(QListWidgetItem *);
	//������Ͽ�Ļ���
	void OnCmbKuCunIndexChanged(int);
	void OnCmbDateIndexChanged(int);
	//ȫѡ��ť
	void OnBtnBkBarSelectClicked();
	//�¼ܰ�ť
	void OnBtnBkBarDeleteClicked();
	void BookDeal();
	//�޸İ�ť
	void OnBtnBkBarAlterClicked();
	void OnBntBkBarChgeHeadClicked();

public:
	//���б�ؼ�����鼮������flagΪtrueʱ���б�ؼ��������е����ߣ����࣬�����磩
	void AddToListBookItem(vector<BookItem>& tvb, bool flag);

private:
	//��ʱ�洢listBook����ʾ�Ľ����BookDealʹ��
	vector<BookItem>listItemBook;
	
	bool bookSelectAll;//�鼮�Ƿ�ȫѡ�ı�־
	//���б�����鼮��ɵı�־����������AddToListBookItem�������ж�BookDeal�����Ĳ��ɿص��ã�
	bool addToListBookFinished;

	//-----------------------------------ͼ�������ϼ�ҳ��--------------------------------

private slots:
	//ѡ���ļ���ť
	void OnBtnSJiaChooseFileClicked();
	//ȷ����ť
	void OnBtnSJiaOKClicked();
	//����ͼƬ��ť
	void OnBtnSJiaChgeHeadClicked();

	//-----------------------------------�û�����ҳ��----------------------------------------------
private slots:
	//���ذ�ť
	void OnBtnUserBarHideClicked();
	//�û����Ұ�ť
	void OnBtnUserBarSearchClicked();
	//����б�ؼ�����Ӧ
	void OnListUserClicked(QListWidgetItem *);
	void UserDeal();
	//�������밴ť
	void OnBtnUserBarResetPW();
	//ȫѡ/ȫ��ѡ��ť
	void OnBtnUserBarSelectAll();
	//ɾ����ť
	void OnBtnUserBarDelete();
	//ȷ����ť
	void OnBtnUserBarOKClicked();

private:
	//��ʱ�洢listUser����ʾ�Ľ������UserDealʹ��
	vector<UserItem>listItemUser;

	bool userSelectAll;//�û��Ƿ�ȫѡ�ı�־
	//���б�����û���ɵı�־����������AddToListUserItem�������ж�UserDeal�����Ĳ��ɿص��ã�
	bool addToListUserFinished;

public:
	//���б�ؼ�����鼮������flagΪtrueʱ���б�ؼ��������е����ߣ����࣬�����磩
	//��ͬȨ���������ݲ�ͬ
	void AddToListUserItem(vector<UserItem>& tvb, bool flag);

//----------------------------------------------------����---------------------------------
private:
	Ui::MgInterface ui;

private slots:
	//�Զ�����С�����رա����ð�ť
	void OnBtnCloseClicked();
	void OnBtnMinClicked();

private:
	//ʵ�ִ��ڿ��϶�
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //�������ڴ����λ��
	bool isMousePressed;    //����Ƿ���
};
