#include "mycoinbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QSound>

//MyCoinButton::MyCoinButton(QWidget *parent) : QPushButton(parent)
//{

//}

MyCoinButton::MyCoinButton(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
      QString str = QString("load faiure:%1").arg(btnImg);
      qDebug()<<str;
      return;
    }
    setFixedSize(pix.width(),pix.height());
    setStyleSheet("QPushButton{border:0px}");
    this->setIcon(QIcon(btnImg));
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器
    timerJToY = new QTimer(this);
    timerYToJ = new QTimer(this);
    //监听金色反转为银币
    connect(timerJToY,&QTimer::timeout,[=](){
      QPixmap pix;
      QString str=QString(":/Image/Coin000%1.png").arg(QString::number(this->minCoinImgIndex++));
      pix.load(str);
      setFixedSize(pix.width(),pix.height());
      setStyleSheet("QPushButton{border:0px}");
      this->setIcon(pix);
      this->setIconSize(QSize(pix.width(),pix.height()));
      //判断如果翻完了将min重置为1
      if(minCoinImgIndex>maxCoinImgIndex)
      {
          minCoinImgIndex=1;
          animateFlag = false;
          timerJToY->stop();
      }
     });

      connect(timerYToJ,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/Image/Coin000%1.png").arg(QString::number(this->maxCoinImgIndex--));
        pix.load(str);
        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断如果翻完了将min重置为1
        if(minCoinImgIndex>maxCoinImgIndex)
        {
            maxCoinImgIndex=8;
            animateFlag = false;
            timerYToJ->stop();
        }
      });
}

void MyCoinButton::mousePressEvent(QMouseEvent *e)
{
    if(animateFlag || isWin )
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}

 void MyCoinButton::changeFlag()
 {
     //如果是正面返程反面
     if(flag)
     {
         //正面翻翻面
         timerJToY->start(30);
         animateFlag = true;
         flag=false;
     }
     else
     {
         timerYToJ->start(30);
         animateFlag =true;
         flag=true;
     }
 }
