#include "materialBroker.h"
#include <QByteArray>
#include <QBuffer>
#include <QDebug>
#include <mutex>

std::shared_ptr<MaterialBroker> MaterialBroker::s_materialBroker=nullptr;
std::mutex MaterialBroker::materialBrokerMutex;

MaterialBroker::~MaterialBroker()
{

}

MaterialBroker::MaterialBroker()
{

}
std::shared_ptr<MaterialBroker> MaterialBroker::getInstance()
{
    //可以用call_once和once_flag替换
    if (s_materialBroker == nullptr) {
        std::unique_lock<std::mutex> lock(materialBrokerMutex);
        if (s_materialBroker == nullptr) {
            auto temp = std::shared_ptr<MaterialBroker>(new MaterialBroker());
            s_materialBroker = temp;
        }
    }
    return s_materialBroker;
}

void MaterialBroker::storeObject(QStringList materials, int noteId)
{
    //把笔记对应的素材存入数据库中的素材表
    std::string insert_cmd = "insert into material(image,number,note_id) values";
    for(int i=0;i<materials.size();i++){
        insert_cmd+="(\""+materials[0].toStdString()+"\","+std::to_string(i)+","+std::to_string(noteId)+"),";
    }
    insert_cmd.pop_back();
    insert(insert_cmd);
}

//Material MaterialBroker::findById(int id)
//{

//}




