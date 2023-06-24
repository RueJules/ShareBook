/*Auther:GongYanxian
Date:2023.6.19*/
#ifndef NOTEBROKER_H
#define NOTEBROKER_H
#include "../Entity/note.h"
#include "relationalBroker.h"
#include <vector>
#include <mutex>


class NoteBroker : public RelationalBroker {


public:
    static std::shared_ptr<NoteBroker> getInstance();//获取单例
//    Note *findById(int noteId);
//    std::vector<int> findMaterials(int id);
    int storeObject(std::string title, std::string content, int materialsCount,std::string imgsrc,QDateTime time ,int bloggerID);
    ~NoteBroker();
    sql::ResultSet * getNotes(int netizenId);
private:
    NoteBroker();
    static std::shared_ptr<NoteBroker> s_noteBroker;
    static std::mutex noteBrokerMutex;
};

#endif
