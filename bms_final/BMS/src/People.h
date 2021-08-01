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

	//���ĸ�����Ϣ
	void AlterOwnInfo(EleUser ele, string str);
	//�鼮�ؼ���ģ�����һ�ISBN��ȷ����
	vector<BookItem> SearchBook(string key);

protected:
	UserItem ownInfo;
};

