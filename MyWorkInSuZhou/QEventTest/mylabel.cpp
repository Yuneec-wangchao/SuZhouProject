#include "mylabel.h"
#include <QDebug>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);//设置鼠标追踪
}

//鼠标进入事件
void myLabel::enterEvent(QEvent *event)
{
   qDebug()<<QString("enterEvent").data();
   event->ignore();
}

//鼠标离开事件鼠标离开事件
void myLabel::leaveEvent(QEvent *event)
{
    qDebug()<<"leaveEvent";
    event->ignore();
}

void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug()<<"mouseMoveEvent";
     ev->ignore();
}

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
     qDebug()<<"mouseReleaseEvent";
      ev->ignore();
}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    ev->button()==Qt::LeftButton;
    ev->button() & Qt::LeftButton;
     qDebug()<<"mousePressEvent";
     qDebug()<<"x: "<<ev->x()<<"\n"<<"y: "<<ev->y();
      qDebug()<<"gx: "<<ev->globalX()<<"\n"<<"gy: "<<ev->globalY();
      ev->ignore();
}
