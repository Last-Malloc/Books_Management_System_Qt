#include "RandomInput.h"

string RandomInput::xingShi = "�������������Ի�����"
"���������ֺι���������֣л���Ʒ��ڶ����̲�Ԭ����"
"������������¬���ֶ̼�κѦҶ�����˶Ŵ����������ν�"
"����ʯҦ̷�����ܽ�½�¿װ״޿�ë���ؽ�ʷ�˺�������"
"�����Ǯ�������׳����Ǻ�������";

string RandomInput::sheng = "��������Ϻ�����ӱ�ɽ���������ֽ����㽭���ո�������ɽ�����Ϻ������Ϲ㶫�����Ĵ������������������ຣ̨�����ɹ������������½���۰���";

string RandomInput::ChineseString(int len)
{
    string tStr, str = "";
    BYTE byte1, byte2;
    int rand2;
    for(int i = 0;i < len;++i)
    {
        srand(unsigned(clock() * (time(NULL))));//�����������Ϊ����ʱ��
        Sleep(3);
        rand2 = 0xfe - 0xa1;
        byte1 = 0xb0;//���к���Ϊbyte1 = rand() % rand1 + 0xb0���˴�ȡ���ú���
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
    str = str + ChineseString(2) + "������";
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
    int xuHao = rand() % 10;//�����޶���10������
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
    string a[8] = {"�ſ���", "���", "��ǿ", "����", "���Ӣ", "������", "����", "����"};
    srand(unsigned(clock() * (time(NULL))));
    int xuHao = rand() % 8;
    Sleep(3);
    return a[xuHao];
}

string RandomInput::SixPublish()
{
    string a[6] = {"�ߵȽ���������", "��е��ҵ������", "���������", "�»�������", "ͬ�ĳ�����", "�ٻ����ճ�����"};
    srand(unsigned(clock() * (time(NULL))));
    int xuHao = rand() % 6;
    Sleep(3);
    return a[xuHao];
}

