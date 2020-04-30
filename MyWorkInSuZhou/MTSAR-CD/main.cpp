#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(QString("://image/black.css"));
    if(file.open(QIODevice::ReadOnly))
    {
        a.setStyleSheet(QString(file.readAll()));
        file.close();
    }
    MainWindow w;
    w.show();

    return a.exec();
}
