#ifndef MYCOINBUTTON_H
#define MYCOINBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>

class MyCoinButton : public QPushButton
{
    Q_OBJECT
public:
   // explicit MyCoinButton(QWidget *parent = nullptr);
    MyCoinButton(QString btnImg);

    void changeFlag();

    //重写按下
   void mousePressEvent(QMouseEvent *e);

 public:
    //金币属性
    int posX;
    int posY;
    bool flag;
    QTimer *timerJToY;
    QTimer *timerYToJ;
    int minCoinImgIndex = 1;
    int maxCoinImgIndex = 8;
    //执行动画的标志
    bool animateFlag=false;
    //胜利的标志
    bool isWin=false;

signals:

public slots:
};

#endif // MYCOINBUTTON_H
