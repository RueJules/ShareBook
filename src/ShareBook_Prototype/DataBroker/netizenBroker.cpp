/*
 * datetime:2023-6-17
 * author:chenzexi
*/

#include<mutex>
#include<QDebug>
#include "netizenBroker.h"
#include "../Entity/netizenProxy.h"
#include "../Entity/messageProxy.h"

std::shared_ptr<NetizenBroker> NetizenBroker::s_netizenBroker = nullptr;
std::mutex NetizenBroker::netizenBrokerMutex;

NetizenBroker::NetizenBroker()
{

}

NetizenBroker::~NetizenBroker()
{

}

std::shared_ptr<NetizenBroker> NetizenBroker::getInstance() {
    //这里使用了两个 if 判断语句进行双检锁
    if (s_netizenBroker == nullptr) {
        std::unique_lock<std::mutex> lock(netizenBrokerMutex);
        if (s_netizenBroker == nullptr) {
            //确保netizenbroker先初始化再让指针指向初始化的位置？？
            auto temp = std::shared_ptr<NetizenBroker>(new NetizenBroker());
            s_netizenBroker = temp;
        }
    }
    return s_netizenBroker;
}

void NetizenBroker::updateCheckNote(int ownId, int noteId)
{
    std::string cmd = "insert into checked_note(netizen_id,note_id) value(" + std::to_string(ownId) + "," + std::to_string(noteId) +")";
    insert(cmd);

}

void NetizenBroker::updatePublishNote(int bloggerId,int noteId) {
    std::string cmd="insert into published_note(blogger_id,note_id) value("+std::to_string(bloggerId)+","+std::to_string(noteId)+")";
    insert(cmd);
}


Netizen NetizenBroker::findById(int Id) {
    // TODO - implement NetizenBroker::findById
    throw "Not yet implemented";
}

void NetizenBroker::matchAccount(int id, std::string psw,Netizen &netizen)
{
    //匹配id和密码是否正确,获取结果集, 匹配成功就进行初始化
    std::string cmd="select * from netizen where id="+std::to_string(id)+" and password=\""+psw+"\"";
    sql::ResultSet *resultSet =query(cmd);
    //判断是否匹配到了账号
    if (resultSet->next()){
        netizen.setId(id);
        netizen.setPassword(psw);
        //处理结果集
        //获取当前这条数据各个字段的值
        sql::SQLString nickname =resultSet->getString(3);
        netizen.setNickName(std::string{nickname});
        //读取头像
        //QPixmap photo；photo.loadFromData(resultSet.getObject(4).toByteArray(), "JPG")
        //读每个列表（如果列表数量为0就不读）如果不为0 就拿着网民的id去对应关系的表中找粉丝、关注者、发布的笔记、消息的id
        int concerns=resultSet->getInt(5);
        int fans=resultSet->getInt(6);
        int messages=resultSet->getInt(7);
        int notes=resultSet->getInt(8);
        qDebug()<<nickname<<concerns<<fans<<messages<<notes;
        //读关注列表
        if(concerns){
            std::string cmd="select concern_id from netizen_concerns where netizen_id="+std::to_string(id);
            sql::ResultSet *concern_set =query(cmd);
            while(concern_set->next()){
                int concern=concern_set->getInt(1);
                NetizenProxy np(id);
                netizen.addConcern(concern,std::move(np));
                }
            }
        //读粉丝列表
        if(fans){
            std::string cmd="select fan_id from netizen_fans where netizen_id="+std::to_string(id);
            sql::ResultSet *fan_set =query(cmd);
            while(fan_set->next()){
                int fan=fan_set->getInt(1);
                NetizenProxy np(id);
                netizen.addFan(fan,std::move(np));
            }
        }
        //读发布笔记的列表
        if(notes){
            std::string cmd="select note_id from published_note where blogger_id="+std::to_string(id);
            sql::ResultSet *note_set =query(cmd);
            while(note_set->next()){
                int note=note_set->getInt(1);
                NoteProxy np(id);
                netizen.addNote(note,std::move(np));
            }
        }
        if(messages){
            std::string cmd="select id from message where recipient="+id;
            sql::ResultSet *message_set = query(cmd);
            while(message_set->next()){
                int message=message_set->getInt(1);
                MessageProxy mp(id);
                netizen.addMessage(message,std::move(mp));
            }
        }

    }
    //todo: 提示网民用户名或密码不正确
}

