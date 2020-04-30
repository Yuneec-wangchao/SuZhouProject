#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    //构造函数 参数1 正常显示图片路径，参数二 按下状态显示的图片路径
    MyPushButton(QString normaImg,QString pressImg = "");

public:
    QString mormalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoomDown();
    void zoomUp();

    //重写鼠标事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
