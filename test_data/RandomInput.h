#ifndef RANDOMINPUT_H
#define RANDOMINPUT_H

#include<windows.h>
#include<ctime>
#include <bits/stdc++.h>

using namespace std;

class RandomInput
{
public:
	static string ChineseString(int len);//随机中文串
	static string DigitString(int len);//随机数字串
	static string UpperString(int len);//随机大写字母串
	static string LowerString(int len);//随机小写字母串
	static string Name();//返回随机姓名
	static string ISBN();//返回随机ISBN
	static string Publisher();//返回随机出版社
	static string Digit(int num);//返回该数字的字符串
	static string Date();//返回随机日期（年.月）
	static string EightAuthor();
	static string SixPublish();

private:
    static string xingShi;
    static string sheng;
};

#endif // RANDOMINPUT_H
