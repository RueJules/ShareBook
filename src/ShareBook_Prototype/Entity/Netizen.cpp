/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include "Netizen.h"

Netizen::Netizen(int id, std::string psw, std::string nickname, QPixmap profile, std::unordered_map<int, NoteProxy> &publishl, std::unordered_map<int, NetizenProxy> &fanl, std::unordered_map<int, NetizenProxy> &concernl, std::unordered_map<int, MessageProxy> messagel):NetizenInterface(id)
{
    //初始化赋值
}
void Netizen::addNote(int noteId, NoteProxy note)
{
    m_pulishNoteList.emplace(noteId,note);
}

void Netizen::addFan(int fanId, NetizenProxy fan)
{
    m_fanList.emplace(fanId,fan);
}

void Netizen::addConcern(int concernId, NetizenProxy concern)
{
    m_concernList.emplace(concernId,concern);
}

void  Netizen::addMessage(int messageId, MessageProxy message){
    m_messageList.emplace(messageId,message);
}

std::string Netizen::get_nickName()
{

}

QPixmap Netizen::get_profileImage()
{

}

void Netizen::get_publishNoteIdList()
{
    //获取当前笔记map中的id和对应的proxy如果proxy中没有实例就取数据库中找
    //查看发布的所有笔记会调用
}

void Netizen::get_fanIdList()
{
    //查看粉丝列表会调用
}

void Netizen::get_concernIdList()
{
    //查看关注列表会调用
}



