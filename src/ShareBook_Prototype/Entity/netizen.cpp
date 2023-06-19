/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include<QDebug>
#include "netizen.h"
#include "netizenProxy.h"
#include "messageProxy.h"
Netizen::Netizen():NetizenInterface{0}{}


//Netizen::Netizen(int id, std::string psw, std::string nickname, QPixmap profile, std::unordered_map<int, NoteProxy> &publishl, std::unordered_map<int, NetizenProxy> &fanl, std::unordered_map<int, NetizenProxy> &concernl, std::unordered_map<int, MessageProxy> messagel):NetizenInterface(id)
//{
//    //初始化赋值
//}
//void Netizen::addNote(int noteId, NoteProxy note)
//{
//    m_pulishNoteList.emplace(noteId,note);
//}
void Netizen::addNote(int noteId, NoteProxy note)
{
    m_pulishNoteList.emplace(noteId,std::move(note));
}
void Netizen::addFan(int fanId, NetizenProxy fan)
{
    m_fanList.emplace(fanId,std::move(fan));
}

void Netizen::addConcern(int concernId, NetizenProxy concern)
{
    m_concernList.emplace(concernId,std::move(concern));
}
void  Netizen::addMessage(int messageId, MessageProxy message){
    m_messageList.emplace(messageId,std::move(message));
}

std::string Netizen::password() const
{
    return m_password;
}

void Netizen::setPassword(const std::string &newPassword)
{
    m_password = newPassword;
}

std::string Netizen::nickName() const
{
    return m_nickName;
}

void Netizen::setNickName(const std::string &newNickName)
{
    m_nickName = newNickName;
}

//QPixmap Netizen::profileImage() const
//{
//    return m_profileImage;
//}

//void Netizen::setProfileImage(const QPixmap &newProfileImage)
//{
//    m_profileImage = newProfileImage;
//}

void Netizen::check()
{
    qDebug()<<id()<<nickName()<<m_profileImage;
}



QList<int> Netizen::get_publishNoteIdList()
{
    QList<int> notes;
    for(std::unordered_map<int,NoteProxy>::iterator it=m_pulishNoteList.begin();it!=m_pulishNoteList.end();it++){
    notes.append(it->first);
    //qDebug()<<it->first;
    }
     return notes;
}

QList<int> Netizen::get_fanIdList()
{
    QList<int> fans;
    for(std::unordered_map<int,NetizenProxy>::iterator it=m_fanList.begin();it!=m_fanList.end();it++){
        fans.append(it->first);
        qDebug()<<it->first;
    }
    return fans;
}

QList<int> Netizen::get_concernIdList()
{
    QList<int> concerns;
    for(std::unordered_map<int,NetizenProxy>::iterator it=m_concernList.begin();it!=m_concernList.end();it++){
        concerns.append(it->first);
       qDebug()<<it->first;
    }
    return concerns;
}

QList<int> Netizen::get_messageIdList()
{
    QList<int> messages;
    for(std::unordered_map<int,MessageProxy>::iterator it=m_messageList.begin();it!=m_messageList.end();it++){
        messages.append(it->first);
        qDebug()<<it->first;
    }
    return messages;
}



