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
    //构造函数
    Netizen(int id, std::string psw, std::string nickname, QPixmap profile, std::unordered_map<int, NoteProxy> &publishl, std::unordered_map<int, NetizenProxy> &fanl, std::unordered_map<int, NetizenProxy> &concernl, std::unordered_map<int, MessageProxy> messagel);

    void addNote(int noteId, NoteProxy note) override;//添加新发布的笔记，应该是返回bool类型？？
    void addFan(int fanId, NetizenProxy fan) override;//添加新的分析
    void addConcern(int concernId, NetizenProxy concern) override;//添加新的关注
    void addMessage(int messageId, MessageProxy message) override;//添加新的消息

    std::string get_nickName();
    QPixmap get_profileImage();
    void get_publishNoteIdList();
    void get_fanIdList();
    void get_concernIdList();

private:

    std::string m_password;
    std::string m_nickName;
    QPixmap m_profileImage;
    std::unordered_map<int, NoteProxy> m_pulishNoteList;
    std::unordered_map<int, NetizenProxy> m_fanList;
    std::unordered_map<int, NetizenProxy> m_concernList;
    std::unordered_map<int, MessageProxy> m_messageList;
    bool m_newNoteMessage;

};

#endif
