#ifndef LVBODIALOG_H
#define LVBODIALOG_H

#include <QDialog>

namespace Ui {
class LVBODialog;
}

class LVBODialog : public QDialog
{
    Q_OBJECT

public:
    explicit LVBODialog(QWidget *parent = 0);
    ~LVBODialog();

private:
    Ui::LVBODialog *ui;
};

#endif // LVBODIALOG_H
