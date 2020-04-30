#include "choselevelscene.h"
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <QSound>
#include "mypushbutton.h"

ChoseLevelScene::ChoseLevelScene(QWidget *parent) : QMainWindow(parent)
{
//配置选择关卡场景
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/Image/Coin0001.png"));
    setWindowTitle(QString("女神选").toUtf8());

    //准备音效
    QSound *sound = new QSound(":/Image/TapButtonSound.wav",this);
    QSound *backSound = new QSound(":/Image/BackButtonSound.wav",this);

    //创建菜单栏
    QMenuBar *menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    QMenu *startMenu = menuBar->addMenu(QString("菜单").toUtf8());

    QAction *quitMenu = startMenu->addAction("quit");

    connect(quitMenu,&QAction::triggered,[=](){
       close();
    });

    //返回按钮
    MyPushButton *backBtn = new MyPushButton\
            (":/Image/BackButton.png",":/Image/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    connect(backBtn,&MyPushButton::clicked,[=](){
        backSound->play();
        emit backToMainScene();
    });

    //创建关卡按钮
    for(int i=0;i<20;i++)
    {
        MyPushButton * menuBtn = new MyPushButton(":/Image/LevelIcon.png");
        //监听每个按钮的点击
        connect(menuBtn,&QPushButton::clicked,[=](){
            sound->play();
           //qDebug()<<QString("you chosed %1").arg(i+1);
            playscene = new PlayScene(i+1);
            this->hide();
            playscene->setGeometry(this->geometry());
            playscene->show();

            connect(playscene,&PlayScene::backToChoseScene,[=](){
                QTimer::singleShot(500,this,[=](){
                    this->setGeometry(playscene->geometry());
                    this->show();
                    delete playscene;
                    playscene = NULL;
                });
            });
        });
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70,130+i/4*70);
        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+i%4*70,130+i/4*70);
        //设置label的对齐方式，设置水平居中和垂直居中
        label->setAlignment(Qt::AlignCenter);
        //让鼠标进行穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

void ChoseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/OtherSceneBg.png");
    painter.drawPixmap(0,0,width(),height(),pix);

    //话图标
    pix.load(":/Image/Title.png");
    //缩放图片
    pix=pix.scaled(pix.width()*1.12,pix.height());

    painter.drawPixmap(10,30,pix);
}
