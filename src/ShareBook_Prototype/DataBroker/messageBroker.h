/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MESSAGEBROKER_H
#define MESSAGEBROKER_H
#include <mutex>
#include "../Entity/message.h"
#include "relationalBroker.h"



class MessageBroker : RelationalBroker {


public:
    //Message findById(int Id);//根据id在数据库内查找
    void storeObject(std::string content, int senderid, QList<int> recipients); //得到消息的所有内容，写入数据库
    static std::shared_ptr<MessageBroker> getInstance();
    ~MessageBroker();

private:
    MessageBroker(); //私有构造函数

    static std::shared_ptr<MessageBroker> s_messageBroker;
    static std::mutex messageBrokerMutex;//单例
};

#endif
