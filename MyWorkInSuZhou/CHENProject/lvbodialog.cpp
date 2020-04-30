#include "lvbodialog.h"
#include "ui_lvbodialog.h"

LVBODialog::LVBODialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LVBODialog)
{
    ui->setupUi(this);
}

LVBODialog::~LVBODialog()
{
    delete ui;
}
