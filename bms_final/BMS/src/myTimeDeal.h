#pragma once

#include <string>
#include <strstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using std::string;
using std::stringstream;

typedef struct
{
	int year;
	int month;
	int day;
}mydate;

//根据借书日期计算归还日期(输入输出格式为2018/8/3)
string MyCalculate(string key);

//返回当前时间，格式为2018/08/06
string GetNowTime();

//当前日期的string字符串转为int数组
mydate DateStringToIntStruct(string key);

//a > b返回true，否则返回false
bool CompareDate(string a, string b);

//当前日期大于输入日期时，返回当前日期超过输入日期的天数(正整数);否则返回-1；
int NowExceedInputDate(string key);
