#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);
    //鼠标进入事件
    void enterEvent(QEvent *event=NULL);
    //鼠标离开事件
    void leaveEvent(QEvent *event=NULL);

    void mouseMoveEvent(QMouseEvent *ev);

    void mouseReleaseEvent(QMouseEvent *ev);

    void mousePressEvent(QMouseEvent *ev);
signals:

public slots:
};

#endif // MYLABEL_H
