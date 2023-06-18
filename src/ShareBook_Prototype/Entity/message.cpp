/*Auther:Huangyihong
Date:2023.6.17*/

#include "Message.h"
Message::Message(QDate date, int sender, QString nickname, QByteArray profile, int recevie):m_time(date), m_sender(sender), m_nickname(nickname), m_profileImage(profile), m_recevie(recevie){

}
