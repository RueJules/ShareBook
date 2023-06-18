/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef NETIZENINTERFACE_H
#define NETIZENINTERFACE_H
#include<QString>
class NotePorxy;
class NetizenProxy;
class NetizenInterface {

public:
    virtual void addNote(QString noteId, NoteProxy note)=0;//添加新发布的笔记，应该是bool类型？？
    virtual void addFan(QString fanId, NetizenProxy fan)=0;//添加新的分析
    virtual void addConcern(QString concernId, NetizenProxy concern)=0;//添加新的关注
    int get_id(){return m_id;}

private:
    int m_id;

};

#endif
