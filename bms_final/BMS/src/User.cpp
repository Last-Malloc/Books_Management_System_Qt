#include "User.h"

User::User(UserItem it):People(it)
{
	ReLoadMyLoan();
}

User::~User()
{
}

int User::ReLoadMyLoan()
{
	myLoan.clear();
	for (int i = 0; i < FileManage::loanData.size();++i)
	{
		if (FileManage::loanData[i].ID == this->ownInfo.ID)
		{
			myLoan.push_back(FileManage::loanData[i]);
		}
	}
	return myLoan.size();
}