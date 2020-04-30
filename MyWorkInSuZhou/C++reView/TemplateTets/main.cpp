#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
using namespace std;
template <class T>
//template<typename T>等价

void swapTemplate(T& value1,T& value2)
{
    T tmp=value1;
    value1=value2;
    value2=tmp;
}

void testSwapTemplate()
{
    int a=2,b=3;
    swapTemplate(a,b);
    qDebug()<<"a: "<<a<<"b: "<<b;
}

template <class T>
void myPrint(T a,T b)
{
    cout<<"template-myPrint"<<endl;
}

void myPrint(int a,int b)
{
    cout<<"myPrint"<<endl;
}

void testMyPrint()
{
    int a=2,b=3;
    myPrint(a,3);
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
 // testSwapTemplate();
    testMyPrint();

    return a.exec();
}
