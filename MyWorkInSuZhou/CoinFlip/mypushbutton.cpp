#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>

//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}
MyPushButton::MyPushButton(QString normaImg,QString pressImg)
{
    this->mormalImgPath = normaImg;
    this->pressImgPath = pressImg;
    QPixmap pix;
    int ret = pix.load(normaImg);
    if(!ret)
    {
        qDebug()<<"图片加载失败";
    }
    //设置固定大小
    setFixedSize(pix.width(),pix.height());

    //设置不规则图片的样式
    setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图标的大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyPushButton::zoomDown()
{
   //创建动画特效的对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画的时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(x(),y(),width(),height()));
    //结束位置
    animation->setEndValue(QRect(x(),y()+10,width(),height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void MyPushButton::zoomUp()
{
    //创建动画特效的对象
     QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
     //设置动画的时间间隔
     animation->setDuration(200);
     //起始位置
     animation->setStartValue(QRect(x(),y()+10,width(),height()));
     //结束位置
     animation->setEndValue(QRect(x(),y(),width(),height()));
     //设置弹跳曲线
     animation->setEasingCurve(QEasingCurve::OutBounce);
     //执行动画
     animation->start();
}

//重写鼠标事件
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    //传入的按下的图片不为空
   if(this->pressImgPath !="")
   {
       QPixmap pix;
       int ret = pix.load(pressImgPath);
       if(!ret)
       {
           qDebug()<<"图片加载失败";
       }
       //设置固定大小
       setFixedSize(pix.width(),pix.height());

       //设置不规则图片的样式
       setStyleSheet("QPushButton{border:0px;}");

       //设置图标
       this->setIcon(pix);

       //设置图标的大小
       this->setIconSize(QSize(pix.width(),pix.height()));
   }
   //让父类执行其他内容
   return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->mormalImgPath !="")
    {
        QPixmap pix;
        int ret = pix.load(mormalImgPath);
        if(!ret)
        {
            qDebug()<<"图片加载失败";
        }
        //设置固定大小
        setFixedSize(pix.width(),pix.height());

        //设置不规则图片的样式
        setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图标的大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}
