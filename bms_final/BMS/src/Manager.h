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
	
	//����ĳ���û�/�鼮�Ľ����¼��flagΪtrueΪ���û�������Ϊ���鼮��
	vector<LoanItem> SearchLoan(string key, bool flag);
};

