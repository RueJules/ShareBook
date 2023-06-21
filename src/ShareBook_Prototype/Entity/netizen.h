/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef NETIZEN_H
#define NETIZEN_H
#include <iostream>
#include <QPixmap>
//#include "noteProxy.h"
//#include "MessageProxy.h"
#include <unordered_map>
#include "netizenInterface.h"
#include "noteProxy.h"
#include "messageProxy.h"
class NetizenProxy;

class Netizen : public NetizenInterface {

public:
//    //构造函数
    Netizen();
//    Netizen(int id, std::string psw, std::string nickname, QPixmap profile, std::unordered_map<int, NoteProxy> &publishl, std::unordered_map<int, NetizenProxy> &fanl, std::unordered_map<int, NetizenProxy> &concernl, std::unordered_map<int, MessageProxy> messagel);

    void addNote(int noteId, NoteProxy &&note) override;//添加新发布的笔记，应该是返回bool类型？？
    void addFan(int fanId, NetizenProxy &&fan) override;//添加新的分析
    void addConcern(int concernId, NetizenProxy &&concern) override;//添加新的关注
    void addMessage(int messageId, MessageProxy &&message) override;//添加新的消息

    QList<int> get_publishNoteIdList();
    QList<int> get_fanIdList();
    QList<int> get_concernIdList();
    QList<int> get_messageIdList();

    std::string password() const;
    void setPassword(const std::string &newPassword);

    std::string nickName() const;
    void setNickName(const std::string &newNickName);

//    QPixmap profileImage() const;
//    void setProfileImage(const QPixmap &newProfileImage);
    void check();

private:

    std::string m_password;
    std::string m_nickName;
    std::string m_profileImage;//头像路径
    std::unordered_map<int, NoteProxy> m_pulishNoteList;
    std::unordered_map<int, NetizenProxy> m_fanList;
    std::unordered_map<int, NetizenProxy> m_concernList;
    std::unordered_map<int, MessageProxy> m_messageList;
//    bool m_newNoteMessage;

};

#endif
