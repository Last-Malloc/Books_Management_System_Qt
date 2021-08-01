#pragma once
#include "People.h"
#include "FileManage.h"

class Manager :
	public People
{
public:
	Manager(UserItem us);
	virtual ~Manager();
	
	vector<UserItem> SearchUser(string key);
	
	//查找某个用户/书籍的借书记录（flag为true为按用户，否则为按书籍）
	vector<LoanItem> SearchLoan(string key, bool flag);
};

