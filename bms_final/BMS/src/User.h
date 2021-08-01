#pragma once
#include "People.h"
#include "FileManage.h"

class User :
	public People
{
public:
	User(UserItem);
	virtual ~User();

public:
	int ReLoadMyLoan();

protected:
	vector<LoanItem>myLoan;
};

