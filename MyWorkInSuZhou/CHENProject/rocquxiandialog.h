#ifndef ROCQUXIANDIALOG_H
#define ROCQUXIANDIALOG_H

#include <QDialog>

namespace Ui {
class ROCquxianDialog;
}

class ROCquxianDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ROCquxianDialog(QWidget *parent = 0);
    ~ROCquxianDialog();

private:
    Ui::ROCquxianDialog *ui;
};

#endif // ROCQUXIANDIALOG_H
