#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <mypushbutton.h>
#include <QTimer>
#include <QSound>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //配置主场景

    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QPixmap(":/Image/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币");

    //准备音效
    QSound *sound = new QSound(":/Image/TapButtonSound.wav",this);

    //推出按钮的实现
    connect(ui->action_quit,&QAction::triggered,[=](){
     close();
    });

    //开始的按钮
    MyPushButton * startBtn = new MyPushButton(":/Image/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5- startBtn->width()*0.5,this->height()*0.7);




    choseScene = new ChoseLevelScene;

    connect(startBtn,&QPushButton::clicked,[=](){
        //播放音效
        sound->play();
        qDebug()<<"clict start";
        startBtn->zoomDown();
        startBtn->zoomUp();

        //延时进入到选择关卡中
        QTimer::singleShot(500,this,[=](){
            //自身隐藏
            hide();
            choseScene->setGeometry(this->geometry());
            choseScene->show();
        });
    });

//返回
    connect(choseScene,&ChoseLevelScene::backToMainScene,[=](){
        QTimer::singleShot(500,this,[=](){
            this->show();
            this->setGeometry(choseScene->geometry());
            choseScene->hide();
        });
    });
}

 void MainScene::paintEvent(QPaintEvent *)
 {
    QPainter painter(this);
    QPixmap pix;

    //画背景图
    pix.load(":/Image/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,width(),height(),pix);

    //话图标
    pix.load(":/Image/Title.png");
    //缩放图片
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);

    painter.drawPixmap(10,30,pix);

 }

MainScene::~MainScene()
{
    delete ui;
}
