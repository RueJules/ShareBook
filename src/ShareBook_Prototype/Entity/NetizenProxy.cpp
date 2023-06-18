/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include "NetizenProxy.h"

NetizenProxy::NetizenProxy(int id):NetizenInterface{id}
{

}

NetizenProxy::NetizenProxy(int id, Netizen &netizen):NetizenInterface{id},m_netizen{netizen}
{

}

void NetizenProxy::addNote(int noteId, NoteProxy note)
{
    m_netizen->addNote(noteId,note);
}

void NetizenProxy::addFan(int fanId, NetizenProxy fan)
{
    m_netizen->addFan(fanId,fan);
}

void NetizenProxy::addConcern(int concernId, NetizenProxy concern)
{
    m_netizen->addConcern(concernId,concern);
}

void NetizenProxy::addMessage(int messageId, MessageProxy message)
{
    m_netizen->addMessage(messageId,message);
}

json NetizenProxy::getAbstract(string netizenId) {

}
json NetizenProxy::getDetails(string netizenId) {

}

void NetizenProxy::receiveMessage() {

}




