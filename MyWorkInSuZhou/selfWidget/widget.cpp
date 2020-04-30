#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击获取当前控件的值
    connect(ui->btn_print,&QPushButton::clicked,ui->widget,[=](){
        qDebug()<<ui->widget->getNum();
    });
    connect(ui->btn_set,&QPushButton::clicked,ui->widget,[=](){
        ui->widget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}
