#ifndef CHOSELEVELSCENE_H
#define CHOSELEVELSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include "playscene.h"

class ChoseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChoseLevelScene(QWidget *parent = nullptr);

public:
    //重写绘图事件
    void paintEvent(QPaintEvent *);
public:
    PlayScene *playscene =NULL;
signals:
    void backToMainScene();

public slots:
};

#endif // CHOSELEVELSCENE_H
