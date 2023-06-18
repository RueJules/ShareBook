/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include "Netizen.h"

void Netizen::addNote(QString noteId, NoteProxy note)
{

}

void Netizen::addFan(QString fanId, NetizenProxy fan)
{

}

void Netizen::addConcern(QString concernId, NetizenProxy concern)
{

}

Netizen::Netizen(int id, QString psw, QString nickname, QPixmap profile, std::unordered_map<int, NoteProxy> &publishl, std::unordered_map<int, NetizenProxy> &fanl, std::unordered_map<int, NetizenProxy> &concernl, std::unordered_map<int, MessageProxy> messagel):NetizenInterface(id)
{
    //初始化赋值
}

QString Netizen::get_nickName()
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

void Netizen::addMessage(int megId, MessageProxy message)
{

}


