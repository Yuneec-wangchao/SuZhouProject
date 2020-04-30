#include "actionwidget.h"
#include <QIcon>

actionWidget::actionWidget(QWidget *parent) : QDialog(parent)
{
    setWindowIcon(QIcon(":/image/MTSAR-CD(128).ico"));
    resize(600,600);
}

void actionWidget::setWindowTitleAndShowThis(const QString &titleName)
{
    setWindowTitle(titleName.toUtf8());
    this->exec();
}
