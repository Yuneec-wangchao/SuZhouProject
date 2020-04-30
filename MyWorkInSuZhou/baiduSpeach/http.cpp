#include "http.h"
#include <QByteArray>
#include <QEventLoop>
#include <QDebug>

http::http(QObject *parent) : QObject(parent)
{

}

bool http::post_sync(const QString &Url,QMap<QString,QString> header,QByteArray requestData,QByteArray &replyData)
{
    //发送请求的对象
    QNetworkAccessManager manager;

    //请求对象
    QNetworkRequest request;
    request.setUrl(Url);
    QMapIterator<QString,QString> it(header);
    while(it.hasNext())
    {
        it.next();
        request.setRawHeader(it.key().toLatin1(),it.value().toLatin1());
    }

    QNetworkReply *reply =  manager.post(request,requestData);
    QEventLoop l;
    //一旦服务器返回，reply会发出信号
    connect(reply,&QNetworkReply::finished,&l,&QEventLoop::quit);
    l.exec();//死循环，reply发出信号，结束循环
    if(reply != nullptr && reply->error() ==QNetworkReply::NoError)
    {
        replyData = reply->readAll();//读取服务器返回的数据
        //qDebug()<<"success: "<<"content: "<<'\n'<<replyData;
        return true;
    }
    else
    {
        qDebug()<<"failure";
        return false;
    }


}
