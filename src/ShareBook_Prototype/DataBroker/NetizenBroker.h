/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef NETIZENBROKER_H
#define NETIZENBROKER_H

class NetizenBroker : RelationalBroker {

public:
    ~NetizenBroker();
    static std::shared_ptr<NetizenBroker> getInstance();//获取单例
    void deleteInstance();//删除单例
    void updateObject(Netizen netizen);//更新数据库
    Netizen findById(string id);//在数据库中根据id查找netizen的信息
    Netizen matchAccount(string id,string psw);//登陆时匹配用户是否存在并获取netizen的用户信息,初始化netizen

private:

    NetizenBroker();

    static std::shared_ptr<NetizenBroker> m_netizenBroker = nullptr;
    static std::mutex netizenBrokerMutex;

};

#endif
