#include "audio.h"
#include <QDebug>
#include <QMessageBox>

Audio::Audio(QObject *parent) : QObject(parent)
{

}

void Audio::startAudio(const QString &fileName)
{
    QAudioDeviceInfo device = QAudioDeviceInfo::defaultInputDevice();
    if(device.isNull())
    {
        QMessageBox::warning(NULL,"not exist device","not exist device");
    }
    else
    {
        //音频编码要求
        QAudioFormat m_format;
        //设置踩品频率
        m_format.setSampleRate(16000);
        //设置单声道
        m_format.setChannelCount(1);
        //设置位深
        m_format.setSampleSize(16);
        //设置编码
        m_format.setCodec("audio/pcm");

        //判断设备是否支持该格式,找寻该设备支持的模式
        if(!device.isFormatSupported(m_format))
        {
            m_format=device.nearestFormat(m_format);
        }

        //打开文件
        m_file=new QFile;
        m_file->setFileName(fileName);
        m_file->open(QIODevice::WriteOnly);

        //创建录音对象
        m_audio = new QAudioInput(m_format,this);
        m_audio->start(m_file);
    }

}

void Audio::stopAudio()
{
    //停止录音
    m_audio->stop();
    m_file->close();
    delete m_file;
    m_file = NULL;
}
