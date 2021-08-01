#include<bits/stdc++.h>
#include"RandomInput.h"

using namespace std;

void PrintToBook(int);

int main()
{
    PrintToBook(60);
    return 0;
}

void PrintToBook(int num)
{
    ofstream myCout("book.txt");
    cout<<"向Book.txt输出数据......"<<endl;
    string tempNum;
    set<string>isbn;
    set<string>suoShuHao;

    for(int i = 0;i < num;++i)
    {
        string ISBN = RandomInput::ISBN();
        while(isbn.find(ISBN) != isbn.end())
            ISBN = RandomInput::ISBN();
        myCout<<ISBN<<"    ";

        //粘贴书名

        myCout<<RandomInput::EightAuthor()<<"  ";

        string SHH = RandomInput::DigitString(2);
        while(suoShuHao.find(SHH) != suoShuHao.end())
            SHH = RandomInput::DigitString(2);
        if(i >= 45)
            myCout<<"TP131  TP131/";
        else if(i >= 30)
            myCout<<"CK452  CK452/";
        else if(i >= 15)
            myCout<<"JL785  JL785/";
        else
            myCout<<"DF896  DF896/";
        myCout<<SHH<<"  ";

        string kuCun = RandomInput::DigitString(2);
        if(kuCun[0] == '0')
            kuCun = kuCun.substr(1, 1);
        myCout<<kuCun<<"  ";

        myCout<<RandomInput::SixPublish()<<"  ";

        myCout<<RandomInput::Date()<<"  ";

        myCout<<":/bookImage/"<<i + 1<<".jpg"<<endl;

        cout<<"已完成："<<i + 1<<"/"<<num<<endl;
    }
    cout<<"向Book.txt输出完成......"<<endl;
    myCout.close();
}
