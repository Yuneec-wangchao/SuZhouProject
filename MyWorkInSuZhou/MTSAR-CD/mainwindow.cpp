#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include "actionwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionWidget *actionW = new  actionWidget(this);

    QAction *fileAction1 = new QAction(QString("新建工程...").toUtf8(),this);
    QAction *fileAction2 =new QAction(QString("打开工程").toUtf8(),this);
    QAction *fileAction3 =new QAction(QString("关闭工程").toUtf8(),this);
    QAction *fileAction4 =new QAction(QString("导入卫星数据").toUtf8(),this);
    QVector<QAction *> actionList;
    ui->menu_file->addAction(fileAction1);
    ui->menu_file->addAction(fileAction2);
    ui->menu_file->addAction(fileAction3);
    ui->menu_file->addAction(fileAction4);
    actionList.push_back(fileAction1);
    actionList.push_back(fileAction2);
    actionList.push_back(fileAction3);
    actionList.push_back(fileAction4);

    QAction *SARAction1 = new QAction(QString("裁剪AOI...").toUtf8(),this);
    QAction *SAReAction2 =new QAction(QString("滤波").toUtf8(),this);
    QAction *SAReAction3 =new QAction(QString("数据掩模").toUtf8(),this);
    QAction *SAReAction4 =new QAction(QString("地理编码").toUtf8(),this);
    QAction *SAReAction5 =new QAction(QString("加减操作").toUtf8(),this);
    ui->menuSAR->addAction(SARAction1);
    ui->menuSAR->addAction(SAReAction2);
    ui->menuSAR->addAction(SAReAction3);
    ui->menuSAR->addAction(SAReAction4);
    ui->menuSAR->addAction(SAReAction5);
    actionList.push_back(SARAction1);
    actionList.push_back(SAReAction2);
    actionList.push_back(SAReAction3);
    actionList.push_back(SAReAction4);
    actionList.push_back(SAReAction5);

    QAction *bianhuaAction2 =new QAction(QString("影像配准").toUtf8(),this);
    QAction *bianhuaAction3 =new QAction(QString("差异图提取").toUtf8(),this);
    QAction *bianhuaAction4 =new QAction(QString("变化区域提取").toUtf8(),this);
    ui->menu_bianhua->addAction(bianhuaAction2);
    ui->menu_bianhua->addAction(bianhuaAction3);
    ui->menu_bianhua->addAction(bianhuaAction4);
    actionList.push_back(bianhuaAction2);
    actionList.push_back(bianhuaAction3);
    actionList.push_back(bianhuaAction4);

    QAction *houchuliAction2 =new QAction(QString("膨胀").toUtf8(),this);
    QAction *houchuliAction3 =new QAction(QString("腐蚀").toUtf8(),this);
    QAction *houchuliAction4 =new QAction(QString("统计面积").toUtf8(),this);
    QAction *houchuliAction5 =new QAction(QString("多数处理").toUtf8(),this);
    ui->menu_houchuli->addAction(houchuliAction2);
    ui->menu_houchuli->addAction(houchuliAction3);
    ui->menu_houchuli->addAction(houchuliAction4);
    ui->menu_houchuli->addAction(houchuliAction5);
    actionList.push_back(houchuliAction2);
    actionList.push_back(houchuliAction3);
    actionList.push_back(houchuliAction4);
    actionList.push_back(houchuliAction5);

    QAction *helpAction2 =new QAction(QString("关于(&A) ...").toUtf8(),this);
    ui->menu_help->addAction(helpAction2);
    actionList.push_back(helpAction2);

    setWindowIcon(QPixmap(":/image/MTSAR-CD(128).ico"));
    resize(600,600);
    setWindowTitle("MTSAR-CD");


    for(int i=0;i<actionList.size();i++)
    {
        connect(actionList[i],&QAction::triggered,[=](){
            actionW->setWindowTitleAndShowThis(actionList[i]->text());
        });
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}
