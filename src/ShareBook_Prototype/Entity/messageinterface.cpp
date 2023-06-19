/*Auther:Huangyihong
Date:2023.6.17*/

#include "messageInterface.h"

MessageInterface::MessageInterface(int new_id):m_id(new_id){

}

int MessageInterface::get_id()
{
    return m_id;
}
