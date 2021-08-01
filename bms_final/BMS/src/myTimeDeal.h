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

//���ݽ������ڼ���黹����(���������ʽΪ2018/8/3)
string MyCalculate(string key);

//���ص�ǰʱ�䣬��ʽΪ2018/08/06
string GetNowTime();

//��ǰ���ڵ�string�ַ���תΪint����
mydate DateStringToIntStruct(string key);

//a > b����true�����򷵻�false
bool CompareDate(string a, string b);

//��ǰ���ڴ�����������ʱ�����ص�ǰ���ڳ����������ڵ�����(������);���򷵻�-1��
int NowExceedInputDate(string key);
