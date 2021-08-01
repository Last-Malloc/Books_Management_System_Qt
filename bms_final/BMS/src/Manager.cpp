#include "Manager.h"

Manager::Manager(UserItem us):People(us)
{
}

Manager::~Manager()
{
}

vector<UserItem> Manager::SearchUser(string key)
{
	vector<UserItem>shResult;

	if ((int)key.size() == 10 && AllIsDigit(key))
	{
		shResult.push_back(*FileManage::SelectUser(key));
	}
	else
	{
		int num = FileManage::GetCount(FileCnt::user_txt);
		for (int i = 0; i < num; ++i)
		{
			if (FileManage::userData[i].name.find(key) != -1 || key.find(FileManage::userData[i].name) != -1)
			{
				shResult.push_back(FileManage::userData[i]);
			}
		}
	}
	return shResult;
}

vector<LoanItem> Manager::SearchLoan(string key, bool flag)
{
	vector<LoanItem>result;
	int num = FileManage::loanData.size();
	if (flag)
	{
		for (int i = 0;i < num;++i)
		{
			if (FileManage::loanData[i].ID == key)
			{
				result.push_back(FileManage::loanData[i]);
			}
		}
	}
	else
	{
		for (int i = 0; i < num; ++i)
		{
			if (FileManage::loanData[i].ISBN == key)
			{
				result.push_back(FileManage::loanData[i]);
			}
		}
	}
	return result;
}