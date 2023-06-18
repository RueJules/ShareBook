/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MESSAGEBROKER_H
#define MESSAGEBROKER_H
#include "../Entity/Message.h"
#include "RelationalBroker.h"


class MessageBroker : RelationalBroker {


public:
    Message findById(QString Id);//根据id在数据库内查找

    void storeObject(Message message); //得到消息的所有内容，写入数据库

    static MessageBroker instance();

private:
    MessageBroker(); //私有构造函数

private:
    MessageBroker messagebroker; //单例
};

#endif
