#ifndef RANDOMINPUT_H
#define RANDOMINPUT_H

#include<windows.h>
#include<ctime>
#include <bits/stdc++.h>

using namespace std;

class RandomInput
{
public:
	static string ChineseString(int len);//������Ĵ�
	static string DigitString(int len);//������ִ�
	static string UpperString(int len);//�����д��ĸ��
	static string LowerString(int len);//���Сд��ĸ��
	static string Name();//�����������
	static string ISBN();//�������ISBN
	static string Publisher();//�������������
	static string Digit(int num);//���ظ����ֵ��ַ���
	static string Date();//����������ڣ���.�£�
	static string EightAuthor();
	static string SixPublish();

private:
    static string xingShi;
    static string sheng;
};

#endif // RANDOMINPUT_H
