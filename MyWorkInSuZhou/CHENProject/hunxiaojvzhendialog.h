#ifndef HUNXIAOJVZHENDIALOG_H
#define HUNXIAOJVZHENDIALOG_H

#include <QDialog>

namespace Ui {
class HunxiaojvzhenDialog;
}

class HunxiaojvzhenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HunxiaojvzhenDialog(QWidget *parent = 0);
    ~HunxiaojvzhenDialog();

private:
    Ui::HunxiaojvzhenDialog *ui;
};

#endif // HUNXIAOJVZHENDIALOG_H
