#include "rocquxiandialog.h"
#include "ui_rocquxiandialog.h"

ROCquxianDialog::ROCquxianDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ROCquxianDialog)
{
    ui->setupUi(this);
}

ROCquxianDialog::~ROCquxianDialog()
{
    delete ui;
}
