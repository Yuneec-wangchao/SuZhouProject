#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    posX(20),
    ui(new Ui::Widget)
{
    setFixedSize(1000,1000);
    ui->setupUi(this);
    connect(ui->btn_move,&QPushButton::clicked,[=](){
        //如果要手动调用绘图时间，需要用update更新,
        posX+=20;
        update();
    });
}

void Widget::paintEvent(QPaintEvent *)
{
//    //实例化画家对象
//    QPainter painter(this);

//    //设置画笔
//    QPen pen(QColor(255,0,0));
//    //设置画笔宽度
//    pen.setWidth(3);

//    //设置画笔的样式
//    pen.setStyle(Qt::DotLine);

//    //让画家使用这个画笔
//    painter.setPen(pen);

//    //设置画刷
//    QBrush brush(QColor(0,255,0));

//    //设置画刷风格
//    brush.setStyle(Qt::Dense3Pattern);

//    //设置画刷
//    painter.setBrush(brush);

//    //画线
//    painter.drawLine(QPoint(0,0),QPoint(100,100));

//    //画椭圆
//    painter.drawEllipse(QPoint(100,100),50,50);

//    //画矩形
//    painter.drawRect(QRect(20,20,50,50));

//    //画文字
//    painter.drawText(QRect(10,200,100,50),"好好学习");

    //////////////////////////高级设置///////////////////////////////
    QPainter painter(this);
    //////////////////////////Test1///////////////////////////////
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置抗锯齿
//    painter.setRenderHint(QPainter::Antialiasing);

//    painter.drawEllipse(QPoint(200,50),50,50);

    //////////////////////////Test2///////////////////////////////
//    painter.drawRect(QRect(20,20,50,50));
//    painter.translate(100,0);
//    painter.drawRect(QRect(20,20,50,50));

    //////////////////////////Test3///////////////////////////////
//    painter.drawRect(QRect(20,20,50,50));
//    painter.translate(100,0);
//    //保存画家的状态
//    painter.save();
//    painter.drawRect(QRect(20,20,50,50));
//    painter.translate(100,0);
//    //还原画家保存的状态
//    painter.restore();
//    painter.drawRect(QRect(20,20,50,50));
    //////////////////////////Test4///////////////////////////////
    if(posX>this->width())
    {
        posX=0;
    }
    painter.drawPixmap(posX,0,QPixmap(":/Image/H12_无纹理.bmp"));

}

Widget::~Widget()
{
    delete ui;
}
