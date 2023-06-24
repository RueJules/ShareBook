/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MESSAGE_H
#define MESSAGE_H
#include <QDateTime>
#include<string>
#include<memory>
#include "messageInterface.h"


class Message : MessageInterface {
public:
    virtual std::string toString() = 0;
//    Message(QDate date, std::string text,int sender, std::string nickname, QByteArray profile, int recevie);
    Message(int id,QDateTime date, int sender,std::string text,int recevie);
private:
    QDateTime m_time;  //消息产生的时间
    int m_sender;  //消息的发送者
    std::string m_text;
    std::string m_nickname; //消息发送者的昵称
    QByteArray m_profileImage;  //消息发送者的头像
    int m_recipient; //消息的接收者

};

#endif
