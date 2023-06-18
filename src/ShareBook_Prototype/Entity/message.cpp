/*Auther:Huangyihong
Date:2023.6.17*/

#include "Message.h"
//Message::Message(QDate date, std::string text, int sender, std::string nickname, QByteArray profile, int recevie):m_time(date), m_text(text), m_sender(sender), m_nickname(nickname), m_profileImage(profile), m_recevie(recevie){

//}

Message::Message(QDateTime date, int sender, std::string text, int recevie): m_time(date), m_text(text), m_sender(sender),  m_recevie(recevie)
{

}
