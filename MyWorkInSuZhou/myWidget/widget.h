#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
    //允许使用信号和曹

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
