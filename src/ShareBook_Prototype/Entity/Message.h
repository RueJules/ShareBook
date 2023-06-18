/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MESSAGE_H
#define MESSAGE_H
#include <QDate>
#include<QString>
#include "MessageInterface.h"

class Message : MessageInterface {
public:
    virtual QString toString() = 0;
//    Message(QDate date, QString text,int sender, QString nickname, QByteArray profile, int recevie);
    Message(QDate date, int sender,QString text,int recevie);
private:
    QDate m_time;  //消息产生的时间
    int m_sender;  //消息的发送者
    QString m_text;
    QString m_nickname; //消息发送者的昵称
    QByteArray m_profileImage;  //消息发送者的头像
    int m_recevie; //消息的接收者

};

#endif
