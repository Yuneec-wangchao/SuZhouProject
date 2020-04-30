#include "chayitutiqudialog.h"
#include "ui_chayitutiqudialog.h"

ChayitutiquDialog::ChayitutiquDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChayitutiquDialog)
{
    ui->setupUi(this);
}

ChayitutiquDialog::~ChayitutiquDialog()
{
    delete ui;
}
