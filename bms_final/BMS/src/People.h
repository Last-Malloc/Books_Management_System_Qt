#pragma once

#include <string>
#include <vector>
#include "FileManage.h"

using std::string;
using std::vector;

class People
{
public:
	People(UserItem);
	virtual ~People();

	//更改个人信息
	void AlterOwnInfo(EleUser ele, string str);
	//书籍关键字模糊查找或ISBN精确查找
	vector<BookItem> SearchBook(string key);

protected:
	UserItem ownInfo;
};

