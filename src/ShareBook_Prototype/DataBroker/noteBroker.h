/*Auther:GongYanxian
Date:2023.6.19*/
#ifndef NOTEBROKER_H
#define NOTEBROKER_H
#include "../Entity/note.h"
#include "relationalBroker.h"
#include <vector>
#include <mutex>


class NoteBroker : RelationalBroker {


public:
    static std::shared_ptr<NoteBroker> getInstance();//获取单例
//    Note *findById(int noteId);
//    std::vector<int> findMaterials(int id);
    int storeObject(std::string title, std::string text, int materialsCount,QDateTime time ,int bloggerID);
    ~NoteBroker();

private:
    NoteBroker();
    static std::shared_ptr<NoteBroker> s_noteBroker;
    static std::mutex noteBrokerMutex;
};

#endif
