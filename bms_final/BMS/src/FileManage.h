#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "TipWindow.h"
#include <cctype>
#include <ios>
#include <sstream>
#include "myTimeDeal.h"

using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;
using std::ios_base;
using std::stringstream;

enum FileCnt
{
	user_txt, book_txt, loan_txt, recent_txt, message_txt
};

//UserItem�п��Ը��ĵ�Ԫ��
enum EleUser
{
	password, power, institute, className, iconName, scProt, answer
};
//BookItem�п��Ը��ĵ�Ԫ��
enum EleBook
{
	name, author, category, tableNumber, storageRate, pubCompany, pubDate, image, introduction
};
//LoanItem�п��Ը��ĵ�Ԫ��
enum EleLoan
{
	retnDate, isRenew
};
//RecentItem�п��Ը��ĵ�Ԫ��
enum EleRecent
{
	rIconName, rembPW
};

typedef struct
{
	string ID;//*����
	string password;
	int power;//�˻����
	string name;
	int sex;//Ĭ��Ϊ��
	string institute;//ѧԺ
	string className;//�༶
	string iconName;//ͷ��(��Ĭ��)
	string scProt;//�ܱ�����
	string answer;//�ܱ���
}UserItem;//�û�Ԫ���ݣ�10�

typedef struct
{
	string ISBN;//*����
	string name;//����
	string author;//����
	string category;//����
	string tableNumber;//�����
	string storageRate;//�������
	string pubCompany;//������
	string pubDate;//��������
	string image;//ͼƬ
	string introduction;//���
}BookItem;//�鼮Ԫ���ݣ�10�

typedef struct
{
	string ID;
	string ISBN;
	string loanDate;//�������ڣ�����/�������2019/4/16
	string retnDate;//Ӧ���黹����
	int isRenew;//�Ƿ������
}LoanItem;//����Ԫ���ݣ�5�

typedef struct
{
	string ID;
	string iconName;//���������QComboBox������ͷ������ź�
	int rembPW;//��ס�����־
}RecentItem;//�����¼Ԫ����(3��)

//��֤ĳ���ַ���(str)�Ƿ��пո�(���ַ���������Ϊname)(�����ո񷵻�false)
bool IsHaveSpace(string str, string name);

//��֤�ַ����Ƿ�ȫΪ����
bool AllIsDigit(string str);

//��֤�Ƿ�ΪISBN��ĸ�ʽ
bool MatchISBN(string key);

//�鼮�Ŀ�潵��
bool cmpKucunDown(BookItem &a, BookItem &b);

//�鼮�Ŀ������
bool cmpKucunUp(BookItem &a, BookItem &b);

//�鼮�ĳ������ڽ���
bool cmpDateDown(BookItem &a, BookItem &b);

//�鼮�ĳ�����������
bool cmpDateUp(BookItem &a, BookItem &b);

//�鼮��ISBN��������ɾ��ʱʹ�ã�(sort����Ĭ������)
bool cmpISBNUp(BookItem &a, BookItem &b);

bool cmpIDUp(UserItem &a, UserItem &b);

bool cmpIDDown(UserItem &a, UserItem &b);

class FileManage
{
public:
	FileManage();
	~FileManage();

public:
	static vector<UserItem>userData;//�û�����
	static vector<BookItem>bookData;//ͼ������
	static vector<LoanItem>loanData;//��������
	static vector<RecentItem>recentData;//�����¼����
	static vector<UserItem>messageData;//����Ա�˻���������

public:
	//���ļ����������
	static void ReLoadAll();
	static int ReLoadUserD();
	static int ReLoadBookD();
	static int ReLoadLoanD(); 
	static int ReLoadRecentD();
	static int ReLoadMessagD();

	//д���ļ�
	static void WriteToBook_Txt();
	static void WriteToUser_Txt();
	static void WriteToLoan_Txt();
	static void WriteToMessage_Txt();
	static void WriteToRecent_Txt();

	//��ȡ�����Ӹ��ļ���¼��
	static int GetCount(FileCnt);
	static void SetCount(FileCnt,int);//intΪ���ӵ���Ŀ

	//�������ݣ�����ԭ���ݵĵ�ַ�����ã�
	static UserItem* SelectUser(string ID);
	static RecentItem* SelectRecent(string ID);
	static BookItem* SelectBook(string ISBN);
	static LoanItem* SelectLoan(string ID, string ISBN);

	//��������
	static void AddUser(UserItem& temp);//InspectUser���������ȷ����
	static void AddMessage(UserItem& temp);//InspectUser���������ȷ����
	static void AddRecent(RecentItem& temp);//�˺��Ѵ��������
	static void AddBook(BookItem& temp);//ISBN�Ѵ��������(ͬ����������������AlterBook��)
	static void AddLoan(LoanItem& temp);//���ֶ��ж��Ƿ���ͬ����¼��ID��ISBN��ͬ��

	//�������ݸ�ʽ������ɿ���(Ĭ�ϻ�##)����������ؼ�ԭʼ���ݣ�
	static bool InspectUser(UserItem& temp);

	//��������
	//����Ϊѧ�ţ����룩�� ����� ���ĺ��ֵ ����ͷ��ʱ��������recent�е�����
	static bool AlterUser(string, EleUser, string);
	static bool AlterBook(string, EleBook, string);//����ΪISBN�����룩�� ����� ���ĺ��ֵ
	static bool AlterLoan(string, string, EleLoan, string);//����ΪID��ISBN�����룩�� ����� ���ĺ��ֵ
	static bool AlterRecent(string, EleRecent, string);//����ΪID�����룩�� ����� ���ĺ��ֵ

	//ɾ������(�����Ż��ķǱ������������ִ��Ч��)
	static void DeleteBook(vector<string>ve);//����ɾ��loanData�е�����
	static void DeleteUser(vector<string>ve);//����ɾ��loanData��recentData�е�����
	static void DeleteLoan(string id, string isbn);
};

