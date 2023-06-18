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


Netizen NetizenBroker::findById(int Id) {
    // TODO - implement NetizenBroker::findById
    throw "Not yet implemented";
}

Netizen NetizenBroker::matchAccount(int id, std::string psw)
{
    //匹配id和密码是否正确,获取结果集, 匹配成功就进行初始化
    std::string cmd="select * from netizen where id="+std::to_string(id)+"and password="+psw;
    ResultSet *resultSet =query(cmd);
    if (result.getRow() == 0){
        //todo: 提示网民用户名或密码不正确
    }
    //处理结果集
    //获取当前这条数据各个字段的值
    std::string nickname = resultSet.getObject(3);
    //读取头像
    //QPixmap photo；photo.loadFromData(resultSet.getObject(4).toByteArray(), "JPG")
    //读每个列表（如果列表数量为0就不读）如果不为0 就拿着网民的id去对应关系的表中找粉丝、关注者、发布的笔记、消息的id
    int concerns=resultSet.getObject(5);
    int fans=resultSet.getObject(6);
    int messages=resultSet.getObject(7);
    int notes=resultSet.getObject(8);

    if(concerns){
        std::string cmd="select concern_id from netizen_concerns where netizen_id="+std::to_string(id);
        sql::ResultSet *resultSet =query(cmd);
        std::unordered_map<int, NetizenProxy> *concerns=new std::unordered_map<int, NetizenProxy>();
        while(resultSet->next()){
            int concern=resultSet.getObject(1);
            NetizenProxy np(id);
            concerns->emplace(concern,np);
        }
    }
    if(fans){
        std::string cmd="select fan_id from netizen_fans where netizen_id="+id;
        ResultSet *resultSet =query(cmd);
        std::unordered_map<int, NetizenProxy> *fans=new std::unordered_map<int, NetizenProxy>();
        while(resultSet->next()){
            int fan=resultSet.getObject(1);
            NetizenProxy np(id);
            fans->emplace(fan,np);
        }
    }
    if(messages){
        std::string cmd="select id from message where recipient="+id;
        ResultSet *resultSet =query(cmd);
        std::unordered_map<int, MessageProxy> *messages=new std::unordered_map<int, MessageProxy>();
        while(resultSet->next()){
            int message=resultSet.getObject(1);
            MessageProxy mp(id);
            messages->emplace(message,np);
        }
    }
    if(notes){
        std::string cmd="select note_id from published_note where blogger_id="+id;
        sql::ResultSet *resultSet =query(cmd);
        std::unordered_map<int, NoteProxy> *notes=new std::unordered_map<int, NoteProxy>();
        while(resultSet->next()){
            int note=resultSet.getObject(1);
            NoteProxy np(id);
            notes->emplace(note,np);
        }
    }

    return new Netizen(id,nickname,);

}

