/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include "NetizenProxy.h"

void NetizenProxy::addNote(QString noteId, NoteProxy note)
{

}

void NetizenProxy::addFan(QString fanId, NetizenProxy fan)
{

}

void NetizenProxy::addConcern(QString concernId, NetizenProxy concern)
{

}

json NetizenProxy::getAbstract(string netizenId) {
	// TODO - implement NetizenProxy::getAbstract
	throw "Not yet implemented";
}
json NetizenProxy::getDetails(string netizenId) {
    // TODO - implement NetizenProxy::getDetails
    throw "Not yet implemented";
}
void NetizenProxy::sendMessage(Message message) {
    QList fans=m_netizen->get_fanIdList();
    for(auto fan:fans)
    {
        //向数据库中指定写入的数据，有发送方的id,发送的消息类型，接收方的id
        //write(message,fan.get_id());

    }
}


void NetizenProxy::receiveMessage() {
	// TODO - implement NetizenProxy::receiveMessage
	throw "Not yet implemented";
}




