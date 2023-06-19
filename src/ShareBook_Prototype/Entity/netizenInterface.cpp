#include "netizenInterface.h"

//string NetizenInterface::get_id() {
//	// TODO - implement NetizenInterface::get_id
//	throw "Not yet implemented";
//}

NetizenInterface::NetizenInterface(int id):m_id(id)
{

}

void NetizenInterface::setId(int newId)
{
    m_id = newId;
}

int NetizenInterface::id() const
{
    return m_id;
}
