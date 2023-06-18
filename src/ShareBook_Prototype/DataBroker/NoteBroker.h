#ifndef NOTEBROKER_H
#define NOTEBROKER_H
#include "../Entity/Note.h"
#include "RelationalBroker.h"


class NoteBroker : RelationalBroker {


public:
    Note findById(int noteId);
    void storeObject(Note note);

    static std::shared_ptr<NoteBroker> getInstance();//获取单例
    void deleteInstance();//删除单例

private:
    static std::shared_ptr<NoteBroker> s_noteBroker = nullptr;
    static std::mutex noteBrokerMutex;
};

#endif
