#include "hunxiaojvzhendialog.h"
#include "ui_hunxiaojvzhendialog.h"

HunxiaojvzhenDialog::HunxiaojvzhenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HunxiaojvzhenDialog)
{
    ui->setupUi(this);
}

HunxiaojvzhenDialog::~HunxiaojvzhenDialog()
{
    delete ui;
}
