/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include "Control.h"
#include "../DataBroker/NetizenBroker.h"


void Control::init(string id=1,string password=123456)
{
    std::shared_ptr netizen=NetizenBroker::getInstance();
    m_localNetizen=netizen->matchAccount(id,password);
    m_localNetizenProxy=new NetizenProxy(local_netizen);
}

void Control::sendMessage() {
	// TODO - implement Control::sendMessage
	throw "Not yet implemented";
}

void Control::createNote(string title, string text, vector<Metrial> metrial, vector<string> keyword, string blogger) {
	// TODO - implement Control::createNote
	throw "Not yet implemented";
}
