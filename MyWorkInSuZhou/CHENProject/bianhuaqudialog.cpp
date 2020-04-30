#include "bianhuaqudialog.h"
#include "ui_bianhuaqudialog.h"

BianHuaQUDialog::BianHuaQUDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BianHuaQUDialog)
{
    ui->setupUi(this);
}

BianHuaQUDialog::~BianHuaQUDialog()
{
    delete ui;
}
