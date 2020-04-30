#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    /////////////////////////////QPixmap////////////////////////
//    //pixmap绘图设备 专门为平台做了优化
//    QPixmap pix(300,300);

//    //填充颜色
//    pix.fill(Qt::gray);

//    //声明画家
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    //保存
//    pix.save("D:\\MyWorkInSuZhou\\QPainterDevice\\pix.png");
     /////////////////////////////QImage////////////////////////
    //image可以对像素进行操作
//    QImage img(300,300,QImage::Format_ARGB32);
//    img.fill(Qt::green);
//    //声明画家
//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::white));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    //保存
//    img.save("D:\\MyWorkInSuZhou\\QPainterDevice\\img.png");
     /////////////////////////////QPicture////////////////////////
    //可以记录和重现绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(QPen(Qt::yellow));
    painter.drawEllipse(QPoint(150,150),100,100);

    //结束画画
    painter.end();

    //保存在磁盘
    pic.save("D:\\MyWorkInSuZhou\\QPainterDevice\\pic.wc");
}

 void Widget::paintEvent(QPaintEvent *)
 {
     QPainter painter(this);
     //利用QImage  对像素进行修改
//     QImage image;
//     image.load(":/Image/img.png");

//     //修改像素点
//     for(int i=50;i<100;i++)
//     {
//         for(int j = 50;j<100;j++)
//         {
//             QRgb value = qRgb(255,0,0);
//             image.setPixel(i,j,value);
//         }
//     }
//     painter.drawImage(0,0,image);

     //重现绘图指令
     QPicture pic;
     pic.load("D:\\MyWorkInSuZhou\\QPainterDevice\\pic.wc");
     painter.drawPicture(QPoint(0,0),pic);
 }

Widget::~Widget()
{
    delete ui;
}
