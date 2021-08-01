#include "FileManage.h"

vector<UserItem> FileManage::userData;//用户数据
vector<BookItem> FileManage::bookData;//图书数据
vector<LoanItem> FileManage::loanData;//借书数据
vector<RecentItem> FileManage::recentData;//最近登录数据
vector<UserItem> FileManage::messageData;//管理员账户申请数据

FileManage::FileManage()
{
}

FileManage::~FileManage()
{
	 
}

void FileManage::ReLoadAll()
{
	ReLoadUserD();
	ReLoadBookD();
	ReLoadLoanD();
	ReLoadRecentD();
	ReLoadMessagD();
}

int FileManage::ReLoadUserD()
{
	ifstream myCin("user.txt");
	int num = GetCount(FileCnt::user_txt);
	userData.clear();
	userData.resize(num);
	for (int i = 0; i < num; ++i)
	{
		myCin >> userData[i].ID >> userData[i].password >> userData[i].power >> userData[i].name >> userData[i].sex 
			>> userData[i].institute >> userData[i].className >> userData[i].iconName >> userData[i].scProt >> userData[i].answer;
	}
	myCin.close();
	return num;
}

int FileManage::ReLoadBookD()
{
	ifstream myCin("book.txt");
	int num = GetCount(FileCnt::book_txt);
	bookData.clear();
	bookData.resize(num);
	for (int i = 0; i < num; ++i)
	{
		myCin >> bookData[i].ISBN >> bookData[i].name >> bookData[i].author >> bookData[i].category >> bookData[i].tableNumber 
			>> bookData[i].storageRate >> bookData[i].pubCompany >> bookData[i].pubDate >> bookData[i].image >> bookData[i].introduction;
	}
	myCin.close();
	return num;
}

int FileManage::ReLoadLoanD()
{
	ifstream myCin("loan.txt");
	int num = GetCount(FileCnt::loan_txt);
	loanData.clear();
	loanData.resize(num);
	for (int i = 0; i < num; ++i)
	{
		myCin >> loanData[i].ID >> loanData[i].ISBN >> loanData[i].loanDate >> loanData[i].retnDate >> loanData[i].isRenew;
	}
	myCin.close();
	return num;
}

int FileManage::ReLoadRecentD()
{
	ifstream myCin("recent.txt");
	int num = GetCount(FileCnt::recent_txt);
	recentData.clear();
	recentData.resize(num);
	for (int i = 0; i < num; ++i)
	{
		myCin >> recentData[i].ID >> recentData[i].iconName >> recentData[i].rembPW;
	}
	myCin.close();
	return num;
}

int FileManage::ReLoadMessagD()
{
	ifstream myCin("message.txt");
	int num = GetCount(FileCnt::message_txt);
	messageData.clear();
	messageData.resize(num);
	for (int i = 0; i < num; ++i)
	{
		myCin >> messageData[i].ID >> messageData[i].password >> messageData[i].power >> messageData[i].name >> messageData[i].sex
			>> messageData[i].institute >> messageData[i].className >> messageData[i].iconName >> messageData[i].scProt >> messageData[i].answer;
	}
	myCin.close();
	return num;
}

void FileManage::WriteToBook_Txt()
{
	ofstream myCout("book.txt");
	for (int i = 0; i < bookData.size(); ++i)
	{
		myCout << bookData[i].ISBN << " " << bookData[i].name << " " << bookData[i].author << " " << bookData[i].category
			<< " " << bookData[i].tableNumber << " " << bookData[i].storageRate << " " << bookData[i].pubCompany
			<< " " << bookData[i].pubDate << " " << bookData[i].image << " " << bookData[i].introduction << endl;
	}
	myCout.close();

	ifstream myCin2("count.txt");
	int a, b, c, d, e;
	myCin2 >> a >> b >> c >> d >> e;
	myCin2.close();
	b = bookData.size();
	ofstream myCout2("count.txt");
	myCout2 << a << endl << b << endl << c << endl << d << endl << e;
	myCout2.close();
}

void FileManage::WriteToUser_Txt()
{
	ofstream myCout("user.txt");
	for (int i = 0; i < userData.size(); ++i)
	{
		myCout << userData[i].ID << " " << userData[i].password << " " << userData[i].power << " " << userData[i].name << " " << userData[i].sex << " " << userData[i].institute
			<< " " << userData[i].className << " " << userData[i].iconName << " " << userData[i].scProt << " " << userData[i].answer << endl;
	}
	myCout.close();

	ifstream myCin2("count.txt");
	int a, b, c, d, e;
	myCin2 >> a >> b >> c >> d >> e;
	myCin2.close();
	a = userData.size();
	ofstream myCout2("count.txt");
	myCout2 << a << endl << b << endl << c << endl << d << endl << e;
	myCout2.close();
}

void FileManage::WriteToLoan_Txt()
{
	ofstream myCout("loan.txt");
	for (int i = 0; i < loanData.size(); ++i)
	{
		myCout << loanData[i].ID << " " << loanData[i].ISBN << " " << loanData[i].loanDate << " " << loanData[i].retnDate
			<< " " << loanData[i].isRenew << endl;
	}
	myCout.close();

	ifstream myCin2("count.txt");
	int a, b, c, d, e;
	myCin2 >> a >> b >> c >> d >> e;
	myCin2.close();
	c = loanData.size();
	ofstream myCout2("count.txt");
	myCout2 << a << endl << b << endl << c << endl << d << endl << e;
	myCout2.close();
}

void FileManage::WriteToMessage_Txt()
{
	ofstream myCout("message.txt");
	for (int i = 0; i < messageData.size(); ++i)
	{
		myCout << messageData[i].ID << " " << messageData[i].password << " " << messageData[i].power << " " << messageData[i].name << " " << messageData[i].sex << " " << messageData[i].institute
			<< " " << messageData[i].className << " " << messageData[i].iconName << " " << messageData[i].scProt << " " << messageData[i].answer << endl;
	}
	myCout.close();

	ifstream myCin2("count.txt");
	int a, b, c, d, e;
	myCin2 >> a >> b >> c >> d >> e;
	myCin2.close();
	e = messageData.size();
	ofstream myCout2("count.txt");
	myCout2 << a << endl << b << endl << c << endl << d << endl << e;
	myCout2.close();
}

void FileManage::WriteToRecent_Txt()
{
	ofstream myCout("recent.txt");
	for (int i = 0; i < recentData.size(); ++i)
	{
		myCout << recentData[i].ID << " " << recentData[i].iconName << " " << recentData[i].rembPW << endl;
	}
	myCout.close();

	ifstream myCin2("count.txt");
	int a, b, c, d, e;
	myCin2 >> a >> b >> c >> d >> e;
	myCin2.close();
	d = recentData.size();
	ofstream myCout2("count.txt");
	myCout2 << a << endl << b << endl << c << endl << d << endl << e;
	myCout2.close();
}

int FileManage::GetCount(FileCnt temp)
{
	ifstream myCin("count.txt");
	int a, b, c, d, e;
	myCin >> a >> b >> c >> d >> e;
	myCin.close();
	if (temp == FileCnt::user_txt)
	{
		return a;
	}
	else if (temp == FileCnt::book_txt)
	{
		return b;
	}
	else if (temp == FileCnt::loan_txt)
	{
		return c;
	}
	else if (temp == FileCnt::recent_txt)
	{
		return d;
	} 
	else
	{
		return e;
	}
}

void FileManage::SetCount(FileCnt temp, int cnt)
{
	ifstream myCin("count.txt");
	int a, b, c, d, e;
	myCin >> a >> b >> c >> d >> e;
	myCin.close();
	if (temp == FileCnt::user_txt)
	{
		a += cnt;
	}
	else if (temp == FileCnt::book_txt)
	{
		b += cnt;
	}
	else if (temp == FileCnt::loan_txt)
	{
		c += cnt;
	}
	else if (temp == FileCnt::recent_txt)
	{
		d += cnt;
	}
	else
	{
		e += cnt;
	}
	ofstream myCout("count.txt");
	myCout << a << endl << b << endl << c << endl << d << endl << e;
	myCout.close();
}

UserItem* FileManage::SelectUser(string ID)
{
	for (int i = 0;i < userData.size();++i)
	{
		if (userData[i].ID == ID)
		{
			return &userData[i];
		}
	}
	return nullptr;
}

RecentItem* FileManage::SelectRecent(string ID)
{
	for (int i = 0; i < recentData.size(); ++i)
	{
		if (recentData[i].ID == ID)
		{
			return &recentData[i];
		}
	}
	return nullptr;
}

BookItem* FileManage::SelectBook(string ISBN)
{
	for (int i = 0; i < bookData.size(); ++i)
	{
		if (bookData[i].ISBN == ISBN)
		{
			return &bookData[i];
		}
	}
	return nullptr;
}

LoanItem* FileManage::SelectLoan(string ID, string ISBN)
{
	for (int i = 0; i < loanData.size();++i)
	{
		if (loanData[i].ID == ID && loanData[i].ISBN == ISBN)
		{
			return &loanData[i];
		}
	}
	return nullptr;
}

void FileManage::AddUser(UserItem& temp)
{
	userData.push_back(temp);
	ofstream myCout("user.txt",ios_base::app);
	myCout<<temp.ID<<" "<<temp.password<<" "<<temp.power<<" "<<temp.name<<" "<<temp.sex<<" "<<temp.institute
		<<" "<<temp.className<<" "<< temp.iconName<<" "<< temp.scProt<<" "<<temp.answer<<endl;
	myCout.close();
	SetCount(FileCnt::user_txt, 1);
}

void FileManage::AddMessage(UserItem& temp)
{
	userData.push_back(temp);
	ofstream myCout("message.txt", ios_base::app);
	myCout << temp.ID << " " << temp.password << " " << temp.power << " " << temp.name << " " << temp.sex << " " << temp.institute
		<< " " << temp.className << " " << temp.iconName << " " << temp.scProt << " " << temp.answer << endl;
	myCout.close();
	SetCount(FileCnt::message_txt, 1);
}

void FileManage::AddRecent(RecentItem& temp)
{
	if (SelectRecent(temp.ID) == nullptr)
	{
		recentData.push_back(temp);
		ofstream myCout("recent.txt", ios_base::app);
		myCout << temp.ID << " " <<temp.iconName << " " << temp.rembPW << endl;
		myCout.close();
		SetCount(FileCnt::recent_txt, 1);
	}
}

void FileManage::AddBook(BookItem& temp)
{
	if (SelectBook(temp.ISBN) == nullptr)
	{
		bookData.push_back(temp);
		ofstream myCout("book.txt", ios_base::app);
		myCout << temp.ISBN << " " << temp.name << " " << temp.author << " " << temp.category
			<< " " << temp.tableNumber << " " << temp.storageRate << " " << temp.pubCompany
			<< " " << temp.pubDate << " " << temp.image << " " << temp.introduction << endl;
		myCout.close();
		SetCount(FileCnt::book_txt, 1);
	}
}

void FileManage::AddLoan(LoanItem& temp)
{
	loanData.push_back(temp);
	ofstream myCout("loan.txt", ios_base::app);
	myCout << temp.ID << " " << temp.ISBN << " " << temp.loanDate << " " << temp.retnDate
		<< " " << temp.isRenew << endl;
	myCout.close();
	SetCount(FileCnt::loan_txt, 1);
}

bool FileManage::InspectUser(UserItem& temp)
{
	//姓名
	if (temp.name.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("姓名不能为空！！！"));
		return false;
	}
	if (!IsHaveSpace(temp.name, "姓名"))
	{
		return false;
	}

	//学号
	if (temp.ID.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("学号不能为空！！！"));
		return false;
	}
	if (!IsHaveSpace(temp.ID, "学号"))
	{
		return false;
	}
	if (temp.ID.size() != 10)
	{
		if (temp.ID.size() == 0)
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("学号不能为空！！！"));
		}
		else
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("学号格式错误，请重新输入！！！"));
		}
		return false;
	}
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			if (temp.ID[i] < '0' || temp.ID[i] > '9')
			{
				TipWindow::Information_OnlyOK(GBK::ToUnicode("学号格式错误，请重新输入！！！"));
				return false;
			}
		}
	}
	if (SelectUser(temp.ID))
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("学号已存在，请重新输入！！！"));
		return false;
	}

	//学院
	if (temp.institute.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("学院不能为空！！！"));
		return false;
	}
	if (!IsHaveSpace(temp.institute, "学院"))
	{
		return false;
	}

	//班级
	if (temp.className.size() == 0)
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("班级不能为空！！！"));
		return false;
	}
	if (!IsHaveSpace(temp.className, "班级"))
	{
		return false;
	}

	//密码
	if (temp.password.empty())
	{
		TipWindow::Information_OnlyOK(GBK::ToUnicode("密码不能为空！！！"));
		return false;
	}
	if (!IsHaveSpace(temp.password, "密码"))
	{
		return false;
	}

	//密保
	if (!IsHaveSpace(temp.scProt, "密保问题"))
	{
		return false;
	}

	//密保答案
	if (!IsHaveSpace(temp.answer, "密保答案"))
	{
		return false;
	}
	
	if (temp.iconName.empty())
	{
		temp.iconName = "./headpor/moren.png";
	}
	if (temp.scProt.empty())
	{
		temp.scProt = temp.answer = "##";
	}
	else
	{
		if (temp.answer.empty())
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode("您设置了密保，故密码答案不能为空！！！"));
			return false;
		}
	}
	return true;
}

bool FileManage::AlterUser(string tID, EleUser ele, string tValue)
{
	UserItem* tUser = SelectUser(tID);
	RecentItem* tRecent;
	if (IsHaveSpace(tValue, "") && tUser != nullptr)
	{
		switch (ele)
		{
		case password:tUser->password = tValue;
			break;
		case power : if (tValue == "1") { tUser->power = 1; }
				   else { tUser->power = 0; }
				   break;
		case institute:tUser->institute = tValue;
			break;
		case className:tUser->className = tValue;
			break;
		case iconName : tUser->iconName = tValue;
			tRecent = SelectRecent(tID);
			if (tRecent)
			{
				AlterRecent(tID, rIconName, tValue);
			}
			break;
		case scProt:tUser->scProt = tValue;
			break;
		case answer:tUser->answer = tValue;
			break;
		}
		WriteToUser_Txt();
		return true;
	}
	else
	{
		return false;
	}
}

bool FileManage::AlterBook(string ISBN, EleBook ele, string tValue)
{
	BookItem* tBook = SelectBook(ISBN);
	if (IsHaveSpace(tValue, "") && tBook != nullptr)
	{
		switch (ele)
		{
		case name:tBook->name = tValue;
			break;
		case author:tBook->author = tValue;
			break;
		case category:tBook->category = tValue;
			break;
		case tableNumber:tBook->tableNumber = tValue;
			break;
		case storageRate:tBook->storageRate = tValue;
			break;
		case pubCompany:tBook->pubCompany = tValue;
			break;
		case pubDate:tBook->pubDate = tValue;
			break;
		case image:tBook->image = tValue;
			break;
		case introduction:tBook->introduction = tValue;
			break;
		}
		WriteToBook_Txt();
		return true;
	}
	else
	{
		return false;
	}
}

bool FileManage::AlterLoan(string ID, string ISBN, EleLoan ele, string tValue)
{
	LoanItem* tLoan = SelectLoan(ID, ISBN);
	if (IsHaveSpace(tValue, "") && tLoan != nullptr)
	{
		switch (ele)
		{
		case retnDate:tLoan->retnDate = tValue;
			break;
		case isRenew:if (tValue == "1"){tLoan->isRenew = 1;}else{tLoan->isRenew = 0;}
			break;
		}
		WriteToLoan_Txt();
		return true;
	}
	else
	{
		return false;
	}
}

bool FileManage::AlterRecent(string ID, EleRecent ele, string tValue)
{
	RecentItem* tRecent = SelectRecent(ID);
	if (IsHaveSpace(tValue, "") && tRecent != nullptr)
	{
		switch (ele)
		{
		case rIconName:tRecent->iconName = tValue;
			break;
		case rembPW:if (tValue == "1")
		{
			tRecent->rembPW = 1;
		} 
		else
		{
			tRecent->rembPW = 0;
		}
			break;
		}
		ofstream myCout("recent.txt");
		for (int i = 0; i < recentData.size(); ++i)
		{
			myCout << recentData[i].ID << " " << recentData[i].iconName << " " << recentData[i].rembPW << endl;
		}
		myCout.close();
		return true;
	}
	else
	{
		return false;
	}
}

void FileManage::DeleteBook(vector<string>ve)
{
	sort(ve.begin(), ve.end());
	sort(bookData.begin(), bookData.end(), cmpISBNUp);
	int cnt = 0;
	for (int i = 0; i < ve.size() && cnt < bookData.size(); ++i)
	{
		if (bookData[cnt].ISBN == ve[i])
		{
			bookData.erase(bookData.begin() + cnt);
			//删除bookData中的元素后其余元素自动向前补充，故cnt不用+1
			//级联删除loanData中的数据
			for (int j = 0; j < loanData.size(); ++j)
			{
				if (loanData[j].ISBN == ve[i])
				{
					loanData.erase(loanData.begin() + j);
					--j;//注意下标后退，否则可能漏删
				}
			}
		}
		else if (bookData[cnt].ISBN > ve[i])
		{
		}
		else
		{
			--i;
			++cnt;
		}
	}
	WriteToBook_Txt();
	WriteToLoan_Txt();
}

void FileManage::DeleteUser(vector<string>ve)
{
	sort(ve.begin(), ve.end());
	sort(userData.begin(), userData.end(), cmpIDUp);
	int cnt = 0;
	for (int i = 0; i < ve.size() && cnt < userData.size(); ++i)
	{
		if (userData[cnt].ID == ve[i])
		{
			userData.erase(userData.begin() + cnt);
			//删除bookData中的元素后其余元素自动向前补充，故cnt不用+1
			//级联删除loanData中的数据
			for (int j = 0; j < loanData.size(); ++j)
			{
				if (loanData[j].ID == ve[i])
				{
					loanData.erase(loanData.begin() + j);
					--j;//注意下标后退，否则可能漏删
				}
			}
			//级联删除recentData中的数据
			for (int j = 0; j < recentData.size(); ++j)
			{
				if (recentData[j].ID == ve[i])
				{
					recentData.erase(recentData.begin() + j);
					--j;//注意下标后退，否则可能漏删
				}
			}
		}
		else if (userData[cnt].ID > ve[i])
		{
		}
		else
		{
			--i;
			++cnt;
		}
	}
	WriteToUser_Txt();
	WriteToLoan_Txt();
	WriteToRecent_Txt();
}

void FileManage::DeleteLoan(string id, string isbn)
{
	for (int i = 0; i < loanData.size(); ++i)
	{
		if (loanData[i].ID == id && loanData[i].ISBN == isbn)
		{
			loanData.erase(loanData.begin() + i);
			break;
		}
	}
	WriteToLoan_Txt();
}

bool IsHaveSpace(string str, string name)
{
	for (int i = 0; i < (int)str.size(); ++i)
	{
		if (str[i] == ' ')
		{
			TipWindow::Information_OnlyOK(GBK::ToUnicode(name + "输入不能包含空格"));
			return false;
		}
	}
	return true;
}

bool AllIsDigit(string str)
{
	for (int i = 0;i < (int)str.size();++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
	}
	return true;
}

bool MatchISBN(string key)
{
	bool isbnFlag = true;
	if (key.size() != 17)
	{
		isbnFlag = false;
	}
	if (isbnFlag)
	{
		if (key[3] != '-' || key[5] != '-' || key[10] != '-' || key[15] != '-')
		{
			isbnFlag = false;
		}
		for (int i = 0; i < 17; ++i)
		{
			if (i != 3 && i != 5 && i != 10 && i != 15)
			{
				if (key[i] < '0' || key[i] > '9')
				{
					isbnFlag = false;
					break;
				}
			}
		}
	}
	return isbnFlag;
}

bool cmpKucunDown(BookItem &a, BookItem &b)
{
	bool temp;
	if (GBK::ToUnicode(a.storageRate).toInt(&temp) > GBK::ToUnicode(b.storageRate).toInt(&temp))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmpKucunUp(BookItem &a, BookItem &b)
{
	bool temp;
	if (GBK::ToUnicode(a.storageRate).toInt(&temp) < GBK::ToUnicode(b.storageRate).toInt(&temp))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmpDateDown(BookItem &a, BookItem &b)
{
	string date_1 = a.pubDate, date_2 = b.pubDate, tempKey = "";
	int year_1, year_2, month_1, month_2;
	int i = 0;
	for (; i < date_1.size() && date_1[i] != '.'; ++i)
	{
		tempKey += date_1[i];
	}
	year_1 = atoi(tempKey.c_str());
	++i;
	tempKey = "";
	for (; i < date_1.size(); ++i)
	{
		tempKey += date_1[i];
	}
	month_1 = atoi(tempKey.c_str());

	i = 0;
	tempKey = "";
	for (; i < date_2.size() && date_2[i] != '.'; ++i)
	{
		tempKey += date_2[i];
	}
	year_2 = atoi(tempKey.c_str());
	++i;
	tempKey = "";
	for (; i < date_2.size(); ++i)
	{
		tempKey += date_2[i];
	}
	month_2 = atoi(tempKey.c_str());

	if (year_1 > year_2 || (year_1 == year_2 && month_1 > month_2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmpDateUp(BookItem &a, BookItem &b)
{
	string date_1 = a.pubDate, date_2 = b.pubDate, tempKey = "";
	int year_1, year_2, month_1, month_2;
	int i = 0;
	for (; i < date_1.size() && date_1[i] != '.'; ++i)
	{
		tempKey += date_1[i];
	}
	year_1 = atoi(tempKey.c_str());
	++i;
	tempKey = "";
	for (; i < date_1.size(); ++i)
	{
		tempKey += date_1[i];
	}
	month_1 = atoi(tempKey.c_str());

	i = 0;
	tempKey = "";
	for (; i < date_2.size() && date_2[i] != '.'; ++i)
	{
		tempKey += date_2[i];
	}
	year_2 = atoi(tempKey.c_str());
	++i;
	tempKey = "";
	for (; i < date_2.size(); ++i)
	{
		tempKey += date_2[i];
	}
	month_2 = atoi(tempKey.c_str());

	if (year_2 > year_1 || (year_1 == year_2 && month_2 > month_1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmpISBNUp(BookItem &a, BookItem &b)
{
	if (b.ISBN > a.ISBN)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmpIDUp(UserItem &a, UserItem &b)
{
	if (b.ID > a.ID)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

bool cmpIDDown(UserItem &a, UserItem &b)
{
	if (b.ID > a.ID)
	{
		return false;
	}
	else
	{
		return true;
	}
}