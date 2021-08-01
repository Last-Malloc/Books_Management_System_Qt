#include "People.h"

People::People(UserItem temp)
{
	ownInfo = temp;
}

People::~People()
{
}

void People::AlterOwnInfo(EleUser ele, string str)
{
	FileManage::AlterUser(ownInfo.ID, ele, str);
}

vector<BookItem> People::SearchBook(string key)
{
	vector<BookItem>shResult;

	if (MatchISBN(key))
	{
		shResult.push_back(*FileManage::SelectBook(key));
	}
	else
	{
		int num = FileManage::GetCount(FileCnt::book_txt);
		for (int i = 0;i < num;++i)
		{
			if (FileManage::bookData[i].name.find(key) != -1 || key.find(FileManage::bookData[i].name) != -1)
			{
				shResult.push_back(FileManage::bookData[i]);
			}
		}
	}
	return shResult;
}