#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include "mycoinbutton.h"


class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
   // explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);
    void paintEvent(QPaintEvent *);
public:
    int levelIndex;//记录关卡
    int gameArray[4][4];//二维数组 维护每关卡的数据
    MyCoinButton *myCoinBtn[4][4];
    //判断是否胜利
    bool isWin;
signals:
    void backToChoseScene();
public slots:
};

#endif // PLAYSCENE_H
