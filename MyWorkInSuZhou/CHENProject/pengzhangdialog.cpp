#include "pengzhangdialog.h"
#include "ui_pengzhangdialog.h"

PengZhangDialog::PengZhangDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PengZhangDialog)
{
    ui->setupUi(this);
}

PengZhangDialog::~PengZhangDialog()
{
    delete ui;
}

 void PengZhangDialog::setWindowSizeLbl(const QString &labelText)
 {
     ui->lbl_windowSize->setText(labelText);
 }


 void PengZhangDialog::setWindowSettingHide()
 {
     ui->le_windowSetting->hide();
     ui->lbl_windowSize->hide();
 }
