/*Auther:Huangyihong
Date:2023.6.17*/

#include "MessageProxy.h"

QString MessageProxy::readMessage() {
    // TODO - implement MessageProxy::getMessage
    throw "Not yet implemented";
}

MessageProxy::MessageProxy()
{

}

MessageProxy::MessageProxy(Message &message)
{
    m_message = message;
}

void MessageProxy::setMessage(Message &message)
{

}
