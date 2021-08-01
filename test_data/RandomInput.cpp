#include "RandomInput.h"

string RandomInput::xingShi = "李王张刘陈杨赵黄周吴"
"徐孙胡朱高林何郭马罗梁宋郑谢韩唐冯于董萧程曹袁邓许"
"傅沈曾彭吕苏卢蒋蔡贾丁魏薛叶阎余潘杜戴夏钟汪田任姜"
"范方石姚谭廖邹熊金陆郝孔白崔康毛邱秦江史顾侯邵孟龙"
"万段漕钱汤尹黎易常武乔贺赖龚文";

string RandomInput::sheng = "北京天津上海重庆河北山西辽宁吉林江苏浙江安徽福建江西山东河南湖北湖南广东海南四川贵州云南陕西甘肃青海台湾内蒙广西西藏宁夏新疆香港澳门";

string RandomInput::ChineseString(int len)
{
    string tStr, str = "";
    BYTE byte1, byte2;
    int rand2;
    for(int i = 0;i < len;++i)
    {
        srand(unsigned(clock() * (time(NULL))));//设置随机种子为毫秒时间
        Sleep(3);
        rand2 = 0xfe - 0xa1;
        byte1 = 0xb0;//所有汉字为byte1 = rand() % rand1 + 0xb0，此处取常用汉字
        byte2 = rand() % rand2 + 0xa1;
        tStr = byte1;
        tStr += byte2;
        str += tStr;
    }
    return str;
}

string RandomInput::DigitString(int len)
{
    string str = "";
    char tChar;
    for(int i = 0;i < len;++i)
    {
        srand(unsigned(clock() * (time(NULL))));
        Sleep(3);
        tChar = '0' + (rand() % 10);
        str += tChar;
    }
    return str;
}

string RandomInput::UpperString(int len)
{
    string str = "";
    char tChar;
    for(int i = 0;i < len;++i)
    {
        srand(unsigned(clock() * (time(NULL))));
        Sleep(3);
        tChar = 'A' + (rand() % 26);
        str += tChar;
    }
    return str;
}

string RandomInput::LowerString(int len)
{
    string str = "";
    char tChar;
    for(int i = 0;i < len;++i)
    {
        srand(unsigned(clock() * (time(NULL))));
        Sleep(3);
        tChar = 'a' + (rand() % 26);
        str += tChar;
    }
    return str;
}

string RandomInput::Name()
{
    srand(unsigned(clock() * (time(NULL))));
    int xuHao = rand() % 100;
    string name = xingShi.substr(xuHao * 2, 2);
    name += ChineseString(2);
    Sleep(3);
    return name;
}

string RandomInput::ISBN()
{
    string str = DigitString(3);
    str += "-";
    str += DigitString(1);
    str += "-";
    str += DigitString(4);
    str += "-";
    str += DigitString(4);
    str += "-";
    str += DigitString(1);
    Sleep(3);
    return str;
}

string RandomInput::Publisher()
{
    srand(unsigned(clock() * (time(NULL))));
    int xuHao = rand() % 33;
    string str = sheng.substr(xuHao * 4, 4);
    str = str + ChineseString(2) + "出版社";
    Sleep(3);
    return str;
}

string RandomInput::Digit(int num)
{
    vector<char>temp;
    char t;
    while(num)
    {
        t = '0' + (num % 10);
        temp.push_back(t);
        num /= 10;
    }
    string str = "";
    while(!temp.empty())
    {
        str += *temp.rbegin();
        temp.pop_back();
    }
    return str;
}

string RandomInput::Date()
{
    int year = 2019;
    srand(unsigned(clock() * (time(NULL))));
    int xuHao = rand() % 10;//日期限定在10年以内
    year -= xuHao;
    Sleep(3);
    srand(unsigned(clock() * (time(NULL))));
    xuHao = rand() % 12;
    ++xuHao;
    Sleep(3);
    string str = Digit(year) + "." + Digit(xuHao);
    return str;
}

string RandomInput::EightAuthor()
{
    string a[8] = {"张俊峰", "李军", "王强", "刘芳", "李桂英", "王秀丽", "姜辉", "韩娜"};
    srand(unsigned(clock() * (time(NULL))));
    int xuHao = rand() % 8;
    Sleep(3);
    return a[xuHao];
}

string RandomInput::SixPublish()
{
    string a[6] = {"高等教育出版社", "机械工业出版社", "人民出版社", "新华出版社", "同心出版社", "百花文艺出版社"};
    srand(unsigned(clock() * (time(NULL))));
    int xuHao = rand() % 6;
    Sleep(3);
    return a[xuHao];
}

