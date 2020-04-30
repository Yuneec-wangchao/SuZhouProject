#include "speech.h"
#include <http.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QHostInfo>
#include <QFile>

speech::speech(QObject *parent) : QObject(parent)
{

}

QString speech::speechIdentify(QString fileName)
{
   //获取access_token
    QString accessToken;
    QString tokenUrl = baiduTokenUrl.arg(client_id).arg(client_secret);
    http m_http;

    QMap<QString,QString> header;
    header.insert(QString("Content-Type"),QString("audio/pcm;rate=16000"));
    QByteArray requestData;//发送的内容
    QByteArray replayData;//服务器返回的

    bool ret=m_http.post_sync(tokenUrl,header,requestData,replayData);
    if(ret)
    {
        QString key= "access_token";
        accessToken =getJsonValue(replayData,key);
        //qDebug()<<accessToken;
    }
    else
    {
       // this->close();
        return "";
    }

    QString speechUrl = baiduSpeechUrl.arg(QHostInfo::localHostName()).arg(accessToken);

    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        requestData = file.readAll();
        file.close();
    }
    replayData.clear();
    //再次发起请求

    ret=m_http.post_sync(speechUrl,header,requestData,replayData);
    if(ret)
    {
        QString key= "result";
        QString text =getJsonValue(replayData,key);
        return text;
        //qDebug()<<accessToken;
    }
    else
    {
       // this->close();
        return "";
    }





    //识别语音


}

 QString speech::getJsonValue(QByteArray array,QString key)
 {
   QJsonParseError parseError;
   QJsonDocument jsonDocument=QJsonDocument::fromJson(array,&parseError);
   if(parseError.error==QJsonParseError::NoError)
   {
       if(jsonDocument.isObject())
       {
           QJsonObject jsonobject = jsonDocument.object();
           if(jsonobject.contains(key))
           {
               QJsonValue jsonValue = jsonobject.value(key);
               if(jsonValue.isString())//字符串
               {
                   return jsonValue.toString();
               }
               else if(jsonValue.isArray())//数组
               {
                  QJsonArray arr = jsonValue.toArray();
                  QJsonValue jv = arr.at(0);
                  return jv.toString();
               }
           }
       }
   }
   else
   {
       return " ";
   }
 }
