#ifndef SPEECH_H
#define SPEECH_H

#include <QObject>
#include <QHostInfo>
//获取access_token相关
const QString baiduTokenUrl = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=%1&client_secret=%2&";
const QString client_id = "OogUkCU9qI7zbbsFFpO5QVt5";
const QString client_secret = "Ms7fGmGILrdMAuWAlTCziMU8WpLN62Yo";

//语音识别相关
const QString baiduSpeechUrl = "http://vop.baidu.com/server_api?dev_pid=1537&cuid=%1&token=%2";

class speech : public QObject
{
    Q_OBJECT
public:
    explicit speech(QObject *parent = nullptr);

    QString speechIdentify(QString fileName);
    QString getJsonValue(QByteArray array,QString key);

signals:

public slots:
};

#endif // SPEECH_H
