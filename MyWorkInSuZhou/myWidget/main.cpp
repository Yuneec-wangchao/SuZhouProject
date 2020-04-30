#include "widget.h"
#include <QApplication>//包含应用程序类

//main函数程序入口
//arg命令行变量的数量 agv命令行变量数组

int main(int argc, char *argv[])
{
    //a为应用程序对象
    QApplication a(argc, argv);
    //窗口对象
    Widget w;
    w.show();
//让a进入消息循环
    return a.exec();
}
