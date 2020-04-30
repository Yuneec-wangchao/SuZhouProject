#ifndef PENGZHANGDIALOG_H
#define PENGZHANGDIALOG_H

#include <QDialog>

namespace Ui {
class PengZhangDialog;
}

class PengZhangDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PengZhangDialog(QWidget *parent = 0);

    void setWindowSizeLbl(const QString &labelText);
    void setWindowSettingHide();
    ~PengZhangDialog();

private:
    Ui::PengZhangDialog *ui;
};

#endif // PENGZHANGDIALOG_H
