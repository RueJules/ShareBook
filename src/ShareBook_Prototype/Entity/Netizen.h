/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef NETIZEN_H
#define NETIZEN_H
#include <iostream>
#include <QPixmap>
#include "NoteProxy.h"
#include "NetizenProxy.h"
#include "MessageProxy.h"
#include <unordered_map>

class Netizen : public NetizenInterface {

public:
    virtual void addNote(QString noteId, NoteProxy note);//添加新发布的笔记，应该是返回bool类型？？
    virtual void addFan(QString fanId, NetizenProxy fan);//添加新的分析
    virtual void addConcern(QString concernId, NetizenProxy concern);//添加新的关注

    //构造函数
    Netizen(int id, QString psw, QString nickname, QPixmap profile, std::unordered_map<int, NoteProxy> &publishl, std::unordered_map<int, NetizenProxy> &fanl, std::unordered_map<int, NetizenProxy> &concernl, std::unordered_map<int, MessageProxy> messagel);
    QString get_nickName();
    QPixmap get_profileImage();
    void get_publishNoteIdList();
    void get_fanIdList();
    void get_concernIdList();
    void addMessage(int megId, MessageProxy message);//添加新的消息（从数据库中拉receiveMessage会调用）

private:

    QString m_password;
    QString m_nickName;
    QPixmap m_profileImage;
    std::unordered_map<int, NoteProxy> m_pulishNoteList;
    std::unordered_map<int, NetizenProxy> m_fanList;
    std::unordered_map<int, NetizenProxy> m_concernList;
    std::unordered_map<int, MessageProxy> m_messageList;
    bool m_newNoteMessage;

};

#endif
