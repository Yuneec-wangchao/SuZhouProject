#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton->setText("speach");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_pressed()
{
    ui->pushButton->setText("release");
    m_audio =new Audio;
    m_audio->startAudio("D:\\1.pcm");
}

void Widget::on_pushButton_released()
{
    m_audio->stopAudio();
    ui->pushButton->setText("start shibie");
    speech m_speech;
    ui->textEdit->setText(m_speech.speechIdentify("D:\\1.pcm"));
    ui->pushButton->setText("speach");
}
