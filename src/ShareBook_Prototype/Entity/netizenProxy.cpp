/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include "netizenProxy.h"
#include "netizen.h"
#include "messageProxy.h"
#include "../DataBroker/messageBroker.h"
NetizenProxy::NetizenProxy():NetizenInterface{0}
{

}

NetizenProxy::NetizenProxy(int id):NetizenInterface{id},m_netizen{nullptr}
{

}

NetizenProxy::NetizenProxy(int id, std::unique_ptr<Netizen>netizen):NetizenInterface{id},m_netizen{std::move(netizen)}
{

}

void NetizenProxy::addNote(int noteId, NoteProxy note)
{
    m_netizen->addNote(noteId,std::move(note));
}

void NetizenProxy::addFan(int fanId, NetizenProxy fan)
{
    m_netizen->addFan(fanId,std::move(fan));
}

void NetizenProxy::addConcern(int concernId, NetizenProxy concern)
{
    m_netizen->addConcern(concernId,std::move(concern));
}

void NetizenProxy::addMessage(int messageId, MessageProxy message)
{
    m_netizen->addMessage(messageId,std::move(message));
}
void NetizenProxy::getDetails()
{

    m_netizen->get_fanIdList();
}

void NetizenProxy::sendMessage(std::string content)
{
    int myself = id();
    QList<int> fans = m_netizen->get_fanIdList();
    MessageBroker::getInstance()->storeObject(content, myself, fans);
}


//json NetizenProxy::getAbstract(string netizenId) {

//}
//json NetizenProxy::getDetails(string netizenId) {

//}

//void NetizenProxy::receiveMessage() {

//}




