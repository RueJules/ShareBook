#include "messageBroker.h"


std::shared_ptr<MessageBroker> MessageBroker::s_messageBroker = nullptr;
std::mutex MessageBroker::messageBrokerMutex;//单例

//Message MessageBroker::findById(int Id) {
//	// TODO - implement MessageBroker::findById
//	throw "Not yet implemented";
//}

void MessageBroker::storeObject(std::string content, int senderid, QList<int> recipients) {
    //通过发送者的id找到发送者的头像路径
//    std::string queryStr = "select profile_photo from netizen where id=" + std::to_string(senderid);
//    sql::ResultSet *res = query(queryStr);
//    std::string path = res->getString("profile_photo");
    QDateTime time=QDateTime::currentDateTime();
    //写入消息
    std::string insertStr = "insert into message(data,time,sender,recipient) values";
    for(auto recipient:recipients){
        insertStr+="(\""+content+"\",\""+time.toString("yyyyMMddhhmmss").toStdString()+"\","+std::to_string(senderid) +"," + std::to_string(recipient) +"),";
    }
    insertStr.pop_back();
    insert(insertStr);
}

std::shared_ptr<MessageBroker> MessageBroker::getInstance() {
    //这里使用了两个 if 判断语句进行双检锁
    if (s_messageBroker == nullptr) {
        std::unique_lock<std::mutex> lock(messageBrokerMutex);
        if (s_messageBroker == nullptr) {
            auto temp = std::shared_ptr<MessageBroker>(new MessageBroker());
            s_messageBroker = temp;
        }
    }
    return s_messageBroker;
}
MessageBroker::MessageBroker(){}
MessageBroker::~MessageBroker(){}
