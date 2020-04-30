#include "widget.h"
#include <QApplication>
#include <QDebug>

//需求，为了传火箭类中的对象，保证只有一个对象实例
class ChairMan
{
    //构造函数私有化
private:
    ChairMan(){
       qDebug()<<"ChairMan";
    }
    ChairMan(const ChairMan& p){}
public:
    static ChairMan * getInstance()
    {
      return singleChairMAN;
    }

private:
    static ChairMan * singleChairMAN;
};

//ChairMan *ChairMan::singleChairMAN = new ChairMan;

//void test01()
//{
//   ChairMan c1;
//   ChairMan *c2 = new ChairMan;
//}

//void test02()
//{
//    ChairMan::singleChairMAN;
//}



//class Printer{
//private:
//    Printer(){};
//    Printer(const Printer &p){};
//    static Printer *singlePrinter;
//public:
//    Printer * getInstance(){
//         return singlePrinter;
//    }

//    void printInl(QString & name)
//    {
//        qDebug()<<name;
//    }
//};

//Printer* Printer::singlePrinter = new Printer();

//void test02()
//{
//    Printer *printer=Printer::getInstance();
//    printer->printInl("123456");
//}


class Cal
{
public:
    void setV1(int v1)
    {
        this->val1 = v1;
    }
    void setV2(int v2)
    {
        this->val2 = v2;
    }

    int GeyResult(QString oper)
    {
        if(oper =="+")
        {
            return this->val1+this->val2;
        }
        else if(oper =="-")
        {
            return this->val1-this->val2;
        }
    }
    int val1;
    int val2;
};

void test01()
{
    Cal cal;
    cal.setV1(1);
    cal.setV2(2);

    qDebug()<< cal.GeyResult("+");
}

void test03()
{
   // int array[10][10]={0};
   int array[10];
    for(int i=0;i<10;i++)
    {
     qDebug()<<array[i];
    }

}

//利用多态实现计算器
class calBase{
public:
    void setV1(int v1)
    {
        this->val1 = v1;
    }
    void setV2(int v2)
    {
        this->val2 = v2;
    }

    virtual int getResult()=0;//纯虚函数
public:
    int val1;
    int val2;
};

class jianfa:public calBase{
public:
    int getResult()
    {
        return this->val1-this->val2;
    }

};

class jiafa:public calBase{
public:
    int getResult()
    {
        return this->val1+this->val2;
    }

};

void test04()
{
    calBase *abc = new jiafa;
    abc->setV1(1);
    abc->setV2(4
               );
    qDebug()<<abc->getResult();
}



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    test04();

    return a.exec();
}

