#include "myTimeDeal.h"

string MyCalculate(string key)
{
	string yy = "", mm = "", dd = "";
	int year, month, day;
	int i = 0;
	for (; i < (int)key.size() && key[i] != '/'; ++i)
	{
		yy += key[i];
	}
	++i;
	for (; i < (int)key.size() && key[i] != '/'; ++i)
	{
		mm += key[i];
	}
	++i;
	for (; i < (int)key.size(); ++i)
	{
		dd += key[i];
	}

	year = atoi(yy.c_str());
	month = atoi(mm.c_str());
	day = atoi(dd.c_str());

	int allDay = 365;
	int dayPerMon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		dayPerMon[1] = dayPerMon[1] + 1;
		allDay = 366;
	}

	day += 30;
	for (int i = 0; i < month - 1; ++i)
	{
		day += dayPerMon[i];
	}

	if (day > allDay)
	{
		++year;
		day %= allDay;
	}

	for (int i = 0; i < 12; ++i)
	{
		if (day <= dayPerMon[i])
		{
			month = i + 1;
			break;
		}
		day -= dayPerMon[i];
	}

	stringstream ss_1, ss_2, ss_3;
	ss_1 << year;
	yy = ss_1.str();
	ss_2 << month;
	mm = ss_2.str();
	ss_3 << day;
	dd = ss_3.str();

	string result;
	result = yy + "/" + mm + "/" + dd;
	return result;
}

string GetNowTime()
{
	time_t timep;
	time(&timep);
	char a[16];
	strftime(a, sizeof(a), "%Y/%m/%d", localtime(&timep));
	string result(a);
	return result;
}

mydate DateStringToIntStruct(string key)
{
	string yy = "", mm = "", dd = "";
	int year, month, day;
	int i = 0;
	for (; i < (int)key.size() && key[i] != '/'; ++i)
	{
		yy += key[i];
	}
	++i;
	for (; i < (int)key.size() && key[i] != '/'; ++i)
	{
		mm += key[i];
	}
	++i;
	for (; i < (int)key.size(); ++i)
	{
		dd += key[i];
	}

	year = atoi(yy.c_str());
	month = atoi(mm.c_str());
	day = atoi(dd.c_str());
	return mydate{ year, month, day };
}

bool CompareDate(string a, string b)
{
	mydate aa = DateStringToIntStruct(a);
	mydate bb = DateStringToIntStruct(b);
	if (aa.year > bb.year || (aa.year == bb.year && aa.month > bb.month) || (aa.year == bb.year && aa.month == bb.month && aa.day > bb.day))
	{
		return true;
	}
	return false;
}

int NowExceedInputDate(string key)
{
	string noww = GetNowTime();
	if (CompareDate(noww, key))
	{
		mydate a = DateStringToIntStruct(noww);
		mydate b = DateStringToIntStruct(key);
		int result;
		//即当前日期和输入日期的月日分别是该年的第几天
		int allDay1 = 0, allDay2 = 0;

		int dayPerMon1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int dayPerMon2[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0))
		{
			dayPerMon1[1] = dayPerMon1[1] + 1;
		}
		if ((b.year % 4 == 0 && b.year % 100 != 0) || (b.year % 400 == 0))
		{
			dayPerMon2[1] = dayPerMon2[1] + 1;
		}
		for (int i = 0;i < a.month - 1;++i)
		{
			allDay1 += dayPerMon1[i];
		}
		allDay1 += a.day;
		for (int i = 0; i < b.month - 1; ++i)
		{
			allDay2 += dayPerMon2[i];
		}
		allDay2 += b.day;

		if (a.year != b.year)
		{
			result = 0;
			for (int i = b.year; i < a.year; ++i)
			{
				if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
				{
					result += 366;
				}
				else
				{
					result += 365;
				}

				if (i == b.year)
				{
					result = result - allDay2 + allDay1;
				}
			}
		}
		else
		{
			result = allDay1 - allDay2;
		}
		return result;
	}
	return 0;
}