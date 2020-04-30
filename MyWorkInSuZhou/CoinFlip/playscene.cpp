#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include <QLabel>
#include <QFont>
#include <QTimer>
#include <QPropertyAnimation>
#include <QSound>
#include <mypushbutton.h>
#include <mycoinbutton.h>
#include "dataconfig.h"
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}
PlayScene::PlayScene(int levelNum)
{
    qDebug()<<QString("inter %1").arg(levelNum);
    levelIndex = levelNum;

    //初始化游戏场景
    //设定固定大小
    setFixedSize(320,588);
    //设置图标
    setWindowIcon(QIcon(":/Image/Coin0001.png"));
    //设置标题
    setWindowTitle(QString("翻金币").toUtf8());

    QSound *backSound = new QSound(":/Image/BackButtonSound.wav",this);
    QSound *winSound = new QSound(":/Image/LevelWinSound.wav",this);
    QSound *clickSound = new QSound(":/Image/ConFlipSound.wav",this);

    //循环十次播放
    //clickSound->setLoops(10);
    //无限循环
    // clickSound->setLoops(-1);
    //clickSound->play();
    //创建菜单栏
    QMenuBar *menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    QMenu *startMenu = menuBar->addMenu(QString("菜单").toUtf8());

    QAction *quitMenu = startMenu->addAction("quit");

    connect(quitMenu,&QAction::triggered,[=](){
       close();
    });

    //返回按钮
    //返回按钮
    MyPushButton *backBtn = new MyPushButton\
            (":/Image/BackButton.png",":/Image/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    connect(backBtn,&MyPushButton::clicked,[=](){
        backSound->play();
        emit backToChoseScene();
    });

    //显示当前关卡数
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(14);
    label->setText(QString("Level:%1").arg(this->levelIndex));
    label->setFont(font);
    label->setGeometry(30,height()-50,120,50);
    DataConfig dataconfig;
    //设置每个关卡的二位数组
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gameArray[i][j]=dataconfig.mData[this->levelIndex][i][j];
        }
    }

    //胜利图片的显示
    QLabel *winLabel = new QLabel;
    winLabel->setParent(this);
    QPixmap winPix;
    winPix.load(":/Image/love.jpg");
    winLabel->setGeometry(0,0,winPix.width(),winPix.height()-40);
    winLabel->setPixmap(winPix);
    winLabel->move((this->width()-winPix.width())*0.5,-winPix.height());

    //显示金币的背景
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            QPixmap pix = QPixmap(":/Image/BoardNode.png");
            QLabel * label = new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57+i*50,200+j*50);

            //创建金币
            QString str;
            if(this->gameArray[i][j] ==1)
            {
                str=":/Image/Coin0001.png";
            }
            else
            {
                str=":/Image/Coin0008.png";
            }


            MyCoinButton *coinBtn = new MyCoinButton(str);
            coinBtn->setParent(this);
            coinBtn->move(59+i*50,204+j*50);

            //给金币属性复制
            coinBtn->posX = i;
            coinBtn->posY = j;
            coinBtn->flag = this->gameArray[i][j];


            //将金币放入到 金币的二位数组中 以便于后期的维护
            myCoinBtn[i][j] = coinBtn;


            connect(coinBtn,&MyCoinButton::clicked,[=](){
                clickSound->play();
                coinBtn->changeFlag();
                this->gameArray[i][j]=this->gameArray[i][j]==0 ? 1:0;

                for(int i =0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        this->myCoinBtn[i][j]->isWin=true;
                    }
                }
                QTimer::singleShot(300,this,[=](){
                    //反转周围的硬币，延时翻转
                    if(coinBtn->posX+1<=3)//反转右侧金币
                    {
                       myCoinBtn[coinBtn->posX+1][coinBtn->posY]->changeFlag();
                       this->gameArray[coinBtn->posX+1][coinBtn->posY]\
                       = this->gameArray[coinBtn->posX+1][coinBtn->posY]==0 ? 1:0;
                    }
                    if(coinBtn->posX-1>=0)//左侧
                    {
                        myCoinBtn[coinBtn->posX-1][coinBtn->posY]->changeFlag();
                        this->gameArray[coinBtn->posX-1][coinBtn->posY]\
                        = this->gameArray[coinBtn->posX-1][coinBtn->posY]==0 ? 1:0;
                    }
                    if(coinBtn->posY+1<=3)//上
                    {
                        myCoinBtn[coinBtn->posX][coinBtn->posY+1]->changeFlag();
                        this->gameArray[coinBtn->posX][coinBtn->posY+1]\
                        = this->gameArray[coinBtn->posX][coinBtn->posY+1]==0 ? 1:0;
                    }
                    if(coinBtn->posY-1>=0)//下
                    {
                        myCoinBtn[coinBtn->posX][coinBtn->posY-1]->changeFlag();
                        this->gameArray[coinBtn->posX][coinBtn->posY-1]\
                        = this->gameArray[coinBtn->posX][coinBtn->posY-1]==0 ? 1:0;
                    }
                    for(int i =0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            this->myCoinBtn[i][j]->isWin=false;
                        }
                    }
                    //判断是都胜利
                    isWin = true;
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            //只要有一个是反面就是失败
                            if(myCoinBtn[i][j]->flag == false)
                            {
                                isWin=false;
                                break;
                            }
                        }
                    }

                    if(isWin)
                    {
                        winSound->play();
                        for(int i=0;i<4;i++)
                        {
                            for(int j=0;j<4;j++)
                            {
                               myCoinBtn[i][j]->isWin=true;
                            }
                        }
                        //将胜利的图片砸下来
                        QPropertyAnimation *animation = new QPropertyAnimation(winLabel,"geometry");
                        //设置时间的间隔
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        //设置结束的位置
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+210,winLabel->width(),winLabel->height()));
                        //设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }
                });


            });
        }
    }

}

void PlayScene::paintEvent(QPaintEvent *)
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
