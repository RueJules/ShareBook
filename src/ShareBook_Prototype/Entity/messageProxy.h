/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MESSAGEPROXY_H
#define MESSAGEPROXY_H
#include "message.h"
#include <string>

class MessageProxy : MessageInterface {

public:
    std::string readMessage();
    MessageProxy(int id);
    MessageProxy(int id,std::unique_ptr<Message> message);
    void setMessage(Message &message);

private:
    std::unique_ptr<Message> m_message;
};

#endif
