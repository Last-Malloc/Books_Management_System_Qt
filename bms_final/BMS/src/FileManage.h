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

//UserItem中可以更改的元素
enum EleUser
{
	password, power, institute, className, iconName, scProt, answer
};
//BookItem中可以更改的元素
enum EleBook
{
	name, author, category, tableNumber, storageRate, pubCompany, pubDate, image, introduction
};
//LoanItem中可以更改的元素
enum EleLoan
{
	retnDate, isRenew
};
//RecentItem中可以更改的元素
enum EleRecent
{
	rIconName, rembPW
};

typedef struct
{
	string ID;//*主码
	string password;
	int power;//账户类别
	string name;
	int sex;//默认为男
	string institute;//学院
	string className;//班级
	string iconName;//头像(可默认)
	string scProt;//密保问题
	string answer;//密保答案
}UserItem;//用户元数据（10项）

typedef struct
{
	string ISBN;//*主码
	string name;//书名
	string author;//作者
	string category;//分类
	string tableNumber;//索书号
	string storageRate;//库存容量
	string pubCompany;//出版社
	string pubDate;//出版日期
	string image;//图片
	string introduction;//简介
}BookItem;//书籍元数据（10项）

typedef struct
{
	string ID;
	string ISBN;
	string loanDate;//借书日期，输入/输出例：2019/4/16
	string retnDate;//应当归还日期
	int isRenew;//是否续借过
}LoanItem;//借书元数据（5项）

typedef struct
{
	string ID;
	string iconName;//仅用作填充QComboBox，不向头像框发射信号
	int rembPW;//记住密码标志
}RecentItem;//最近登录元数据(3项)

//验证某个字符串(str)是否含有空格(该字符串的作用为name)(包含空格返回false)
bool IsHaveSpace(string str, string name);

//验证字符串是否全为数字
bool AllIsDigit(string str);

//验证是否为ISBN码的格式
bool MatchISBN(string key);

//书籍的库存降序
bool cmpKucunDown(BookItem &a, BookItem &b);

//书籍的库存升序
bool cmpKucunUp(BookItem &a, BookItem &b);

//书籍的出版日期降序
bool cmpDateDown(BookItem &a, BookItem &b);

//书籍的出版日期升序
bool cmpDateUp(BookItem &a, BookItem &b);

//书籍的ISBN升序（数据删除时使用）(sort函数默认升序)
bool cmpISBNUp(BookItem &a, BookItem &b);

bool cmpIDUp(UserItem &a, UserItem &b);

bool cmpIDDown(UserItem &a, UserItem &b);

class FileManage
{
public:
	FileManage();
	~FileManage();

public:
	static vector<UserItem>userData;//用户数据
	static vector<BookItem>bookData;//图书数据
	static vector<LoanItem>loanData;//借书数据
	static vector<RecentItem>recentData;//最近登录数据
	static vector<UserItem>messageData;//管理员账户申请数据

public:
	//从文件载入各数据
	static void ReLoadAll();
	static int ReLoadUserD();
	static int ReLoadBookD();
	static int ReLoadLoanD(); 
	static int ReLoadRecentD();
	static int ReLoadMessagD();

	//写入文件
	static void WriteToBook_Txt();
	static void WriteToUser_Txt();
	static void WriteToLoan_Txt();
	static void WriteToMessage_Txt();
	static void WriteToRecent_Txt();

	//获取，增加各文件记录数
	static int GetCount(FileCnt);
	static void SetCount(FileCnt,int);//int为增加的数目

	//查找数据（返回原数据的地址，慎用）
	static UserItem* SelectUser(string ID);
	static RecentItem* SelectRecent(string ID);
	static BookItem* SelectBook(string ISBN);
	static LoanItem* SelectLoan(string ID, string ISBN);

	//增加数据
	static void AddUser(UserItem& temp);//InspectUser处理过的正确数据
	static void AddMessage(UserItem& temp);//InspectUser处理过的正确数据
	static void AddRecent(RecentItem& temp);//账号已存在则忽略
	static void AddBook(BookItem& temp);//ISBN已存在则忽略(同种书数量的增加在AlterBook中)
	static void AddLoan(LoanItem& temp);//需手动判断是否有同样记录（ID和ISBN相同）

	//检验数据格式并处理可空项(默认或##)（接受输入控件原始数据）
	static bool InspectUser(UserItem& temp);

	//更改数据
	//参数为学号（主码）， 更改项， 更改后的值 更改头像时并发更改recent中的数据
	static bool AlterUser(string, EleUser, string);
	static bool AlterBook(string, EleBook, string);//参数为ISBN（主码）， 更改项， 更改后的值
	static bool AlterLoan(string, string, EleLoan, string);//参数为ID和ISBN（主码）， 更改项， 更改后的值
	static bool AlterRecent(string, EleRecent, string);//参数为ID（主码）， 更改项， 更改后的值

	//删除数据(采用优化的非遍历方法以提高执行效率)
	static void DeleteBook(vector<string>ve);//级联删除loanData中的数据
	static void DeleteUser(vector<string>ve);//级联删除loanData和recentData中的数据
	static void DeleteLoan(string id, string isbn);
};

