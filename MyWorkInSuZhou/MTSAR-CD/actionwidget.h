#ifndef ACTIONWIDGET_H
#define ACTIONWIDGET_H

#include <QDialog>

class actionWidget : public QDialog
{
    Q_OBJECT
public:
    explicit actionWidget(QWidget *parent = nullptr);

    void setWindowTitleAndShowThis(const QString &titleName);

signals:

public slots:


};

#endif // ACTIONWIDGET_H
