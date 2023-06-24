/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef NETIZENBROKER_H
#define NETIZENBROKER_H
#include <memory>
#include <string>
#include "../Entity/netizen.h"
#include "relationalBroker.h"

class NetizenBroker : public RelationalBroker {

public:
    ~NetizenBroker();
    static std::shared_ptr<NetizenBroker> getInstance();//获取单例
    void updatePublishNote(int bloggerId,int noteId);//更新数据库(发布的笔记的表)
    void updateCheckNote(int ownId, int noteId); //在数据库中更新网民查看过的笔记
    Netizen findById(int id);//在数据库中根据id查找netizen的信息
    void matchAccount(int id, std::string psw,Netizen &netizen);//登陆时匹配用户是否存在并获取netizen的用户信息,初始化netizen

private:

    NetizenBroker();

    static std::shared_ptr<NetizenBroker> s_netizenBroker;
    static std::mutex netizenBrokerMutex;

};

#endif
