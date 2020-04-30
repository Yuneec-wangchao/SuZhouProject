#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("://Image/H12_无纹理.bmp"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//添加资源文件
//将图片文件夹拷贝到当前工程文件夹
//右键项目 ->添加新文件 -> Qt recourse File ->给资源起名
//例如起名res 生成res.qrc
//open in editor 编辑资源
//添加前缀 添加文件
//使用 “:+前缀名 + 文件名”
