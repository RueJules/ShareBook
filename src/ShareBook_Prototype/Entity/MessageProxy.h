/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MESSAGEPROXY_H
#define MESSAGEPROXY_H
#include "Message.h"
#include <string>

class MessageProxy : MessageInterface {

public:
    std::string readMessage();
    MessageProxy();
    MessageProxy(Message &message);
    void setMessage(Message &message);

private:
    Message* m_message;
};

#endif
