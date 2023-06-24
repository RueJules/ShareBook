/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef NETIZENINTERFACE_H
#define NETIZENINTERFACE_H
#include<string>
#include"noteProxy.h"
class NetizenProxy;
class MessageProxy;
class NetizenInterface {

public:
    NetizenInterface(int id);
    virtual void addNote(int noteId, NoteProxy &&note)=0;//添加新发布的笔记，应该是bool类型？？
    virtual void addFan(int fanId, NetizenProxy &&fan)=0;//添加新的粉丝
    virtual void addConcern(int concernId, NetizenProxy &&concern)=0;//添加新的关注
    virtual void addMessage(int messageId, MessageProxy &&message)=0;//添加新的消息
    virtual void addFootMark(int checkNoteId, NoteProxy &&checkNote) = 0;

    void setId(int newId);
    int id() const;

private:
    int m_id;

};

#endif
