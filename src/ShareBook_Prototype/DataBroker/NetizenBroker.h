/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef NETIZENBROKER_H
#define NETIZENBROKER_H
#include <memory>
#include <string>
#include "../Entity/Netizen.h"
#include "RelationalBroker.h"

class NetizenBroker : RelationalBroker {

public:
    ~NetizenBroker();
    static std::shared_ptr<NetizenBroker> getInstance();//获取单例
    void deleteInstance();//删除单例
    void updateObject(Netizen netizen);//更新数据库
    Netizen findById(int id);//在数据库中根据id查找netizen的信息
    Netizen matchAccount(int id, std::string psw);//登陆时匹配用户是否存在并获取netizen的用户信息,初始化netizen

private:

    NetizenBroker();

    static std::shared_ptr<NetizenBroker> s_netizenBroker = nullptr;
    static std::mutex netizenBrokerMutex;

};

#endif
