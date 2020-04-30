#ifndef BIANHUAQUDIALOG_H
#define BIANHUAQUDIALOG_H

#include <QDialog>

namespace Ui {
class BianHuaQUDialog;
}

class BianHuaQUDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BianHuaQUDialog(QWidget *parent = 0);
    ~BianHuaQUDialog();

private:
    Ui::BianHuaQUDialog *ui;
};

#endif // BIANHUAQUDIALOG_H
