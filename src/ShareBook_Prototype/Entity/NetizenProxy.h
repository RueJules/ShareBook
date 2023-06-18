/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef NETIZENPROXY_H
#define NETIZENPROXY_H
#include "NetizenInterface.h"
#include "Netizen.h"
class NetizenProxy : public NetizenInterface {

public:
    //netizen中是简单的添加，proxy中可能有一些处理
    virtual void addNote(QString noteId, NoteProxy note);//添加新发布的笔记，应该是bool类型？？
    virtual void addFan(QString fanId, NetizenProxy fan);//添加新的分析
    virtual void addConcern(QString concernId, NetizenProxy concern);//添加新的关注

    json getAbstract(int netizenId);//获取网民的概要信息（在显示笔记、评论、消息时）包括网民的头像和昵称
    json getDetails(int netizenId);//获取网民的详细信息（在展示个人主页时）
    void sendMessage(int id);//给网民发送消息
    void receiveMessage();//网民查看到自己有未读消息时（newMessage属性为true）从数据库中拉取消息到消息列表中
private:
    Netizen* m_netizen;
};

#endif