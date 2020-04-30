#ifndef CHAYITUTIQUDIALOG_H
#define CHAYITUTIQUDIALOG_H

#include <QDialog>

namespace Ui {
class ChayitutiquDialog;
}

class ChayitutiquDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChayitutiquDialog(QWidget *parent = 0);
    ~ChayitutiquDialog();

private:
    Ui::ChayitutiquDialog *ui;
};

#endif // CHAYITUTIQUDIALOG_H
