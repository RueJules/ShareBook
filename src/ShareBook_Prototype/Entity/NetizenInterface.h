/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef NETIZENINTERFACE_H
#define NETIZENINTERFACE_H
#include<string>
class NotePorxy;
class NetizenProxy;
class MessageProxy;
class NetizenInterface {

public:
    virtual void addNote(int noteId, NoteProxy note)=0;//添加新发布的笔记，应该是bool类型？？
    virtual void addFan(int fanId, NetizenProxy fan)=0;//添加新的分析
    virtual void addConcern(int concernId, NetizenProxy concern)=0;//添加新的关注
    virtual void addMessage(int messageId, MessageProxy message)=0;
    int get_id(){return m_id;}

    NetizenInterface(int id);

private:
    int m_id;

};

#endif
