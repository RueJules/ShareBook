/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include "NetizenBroker.h"
#include<mutex>

NetizenBroker *NetizenBroker::m_netizenBroker = nullptr;
std::mutex NetizenBroker::m_Mutex;

NetizenBroker::NetizenBroker()
    {
        std::cout << "构造函数" << std::endl;
    }

NetizenBroker::~NetizenBroker()
    {
        std::cout << "析构函数" << std::endl;
    }

std::shared_ptr<NetizenBroker> NetizenBroker::getInstance() {
    //这里使用了两个 if 判断语句进行双检锁
    if (m_netizenBroker == nullptr) {
        std::unique_lock<std::mutex> lock(netizenBrokerMutex);
        if (m_netizenBroker == nullptr) {
            //确保netizenbroker先初始化再让指针指向初始化的位置？？
            auto temp = std::shared_ptr<NetizenBroker>(new NetizenBroker());
            m_netizenBroker = temp;
        }
    }
    return m_netizenBroker;
}

void NetizenBroker::deleteInstance()
{
    std::unique_lock<std::mutex> lock(m_Mutex); // 加锁
    if (m_netizenBroker)
    {
        delete m_netizenBroker;
        m_netizenBroker = nullptr;
    }
}

void NetizenBroker::updateObject(Netizen netizen) {
    // TODO - implement NetizenBroker::updateObject
    throw "Not yet implemented";
}


Netizen NetizenBroker::findById(string Id) {
    // TODO - implement NetizenBroker::findById
    throw "Not yet implemented";
}

Netizen NetizenBroker::matchAccount(string id, string psw)
{
    //匹配id和密码是否正确
    //匹配成功就进行初始化
    //读他的昵称和头像
    //读每个列表（如果列表数量为0就不读）如果不为0 就拿着网民的id去对应关系的表中找粉丝、关注者、发布的笔记、消息的id
}

