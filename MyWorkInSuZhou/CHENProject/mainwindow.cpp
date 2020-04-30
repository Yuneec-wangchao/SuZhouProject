#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lvbodialog.h"
#include "chayitutiqudialog.h"
#include "bianhuaqudialog.h"
#include "pengzhangdialog.h"
#include "hunxiaojvzhendialog.h"
#include "rocquxiandialog.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file(QString(":/Image/black.css"));
    if(file.open(QIODevice::ReadOnly))
    {
        setStyleSheet(file.readAll());
        file.close();
    }
    setWindowIcon(QIcon(":/Image/MTSAR-CD(128).ico"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

template <class T,class T1>
void MainWindow::showThis(T &a,T1 &b)
{
    a.resize(400,250);
    a.setWindowTitle(QString(b).toUtf8());
    a.exec();
}

void MainWindow::on_pushButton_clicked()
{
   LVBODialog *lvbow =new  LVBODialog(this);
   showThis(*lvbow,"滤波");
}

void MainWindow::on_pushButton_2_clicked()
{
    ChayitutiquDialog *lvbow =new  ChayitutiquDialog(this);
    showThis(*lvbow,"差异图提取");

}

void MainWindow::on_pushButton_3_clicked()
{
    BianHuaQUDialog *lvbow =new  BianHuaQUDialog(this);
    showThis(*lvbow,"变化区域提取");
}

void MainWindow::on_pushButton_4_clicked()
{
    PengZhangDialog *lvbow =new  PengZhangDialog(this);
    lvbow->setWindowSizeLbl("膨胀窗口大小：");
    showThis(*lvbow,"膨胀");
}

void MainWindow::on_pushButton_5_clicked()
{
    PengZhangDialog *lvbow =new  PengZhangDialog(this);
    lvbow->setWindowSizeLbl("腐蚀窗口大小：");
    showThis(*lvbow,"腐蚀");
}

void MainWindow::on_pushButton_6_clicked()
{
    PengZhangDialog *lvbow =new  PengZhangDialog(this);
    lvbow->setWindowSizeLbl("多数处理窗口大小：");
    showThis(*lvbow,"多数处理");
}

void MainWindow::on_pushButton_7_clicked()
{
    PengZhangDialog *lvbow =new  PengZhangDialog(this);
    lvbow->setWindowSettingHide();
    showThis(*lvbow,"统计面积");
}

void MainWindow::on_pushButton_8_clicked()
{
    HunxiaojvzhenDialog *lvbow =new  HunxiaojvzhenDialog(this);
    showThis(*lvbow,"混淆矩阵");
}

void MainWindow::on_pushButton_9_clicked()
{
    ROCquxianDialog *lvbow =new  ROCquxianDialog(this);
    showThis(*lvbow,"ROC曲线");
}
