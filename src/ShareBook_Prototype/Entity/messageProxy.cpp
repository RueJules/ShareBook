/*Auther:Huangyihong
Date:2023.6.17*/

#include "messageProxy.h"

std::string MessageProxy::readMessage() {
    // TODO - implement MessageProxy::getMessage
    throw "Not yet implemented";
}

MessageProxy::MessageProxy(int id):MessageInterface{id}
{

}

MessageProxy::MessageProxy(int id,std::unique_ptr<Message>message):MessageInterface{id},m_message{std::move(message)}
{
}

void MessageProxy::setMessage(Message &message)
{

}
