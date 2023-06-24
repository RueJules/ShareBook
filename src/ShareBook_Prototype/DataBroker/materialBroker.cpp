#include "materialBroker.h"
#include "../Entity/materialProxy.h"
#include <QByteArray>
#include <QBuffer>
#include <QDebug>
#include <mutex>
#include <QPixmap>
#include <QString>
#include <memory>

std::shared_ptr<MaterialBroker> MaterialBroker::s_materialBroker=nullptr;
std::mutex MaterialBroker::materialBrokerMutex;

MaterialBroker::~MaterialBroker()
{

}

std::vector<MaterialProxy> MaterialBroker::getNoteMaterials(int noteId)
{
    std::string cmd = "select *from material where note_id=" + std::to_string(noteId);
    sql::ResultSet *res = query(cmd);
    std::vector<MaterialProxy> mas;
    while(res->next()){
        int id = res->getInt(1);
        std::string imageSrc = res->getString(2).c_str();
        QPixmap pixmap(QString::fromStdString(imageSrc));
        int order = res->getInt(3);
        std::unique_ptr<Material> material = std::make_unique<Material>(id, pixmap, order);
        MaterialProxy mp(id,std::move(material));
        mas.emplace_back(std::move(mp));
    }
    return mas;
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




