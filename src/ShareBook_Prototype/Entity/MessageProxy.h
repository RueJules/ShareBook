/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MESSAGEPROXY_H
#define MESSAGEPROXY_H
#include "Message.h"
#include <QString>

class MessageProxy : MessageInterface {

public:
    QString readMessage();
    MessageProxy();
    MessageProxy(Message &message);
    void setMessage(Message &message);

private:
    Message* m_message;
};

#endif
