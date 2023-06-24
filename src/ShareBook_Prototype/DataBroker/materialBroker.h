/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MATERIALBROKER_H
#define MATERIALBROKER_H
#include "relationalBroker.h"
#include <QPixmap>
#include "../Entity/materialProxy.h"

class MaterialBroker : public RelationalBroker
{
public:
    static  std::shared_ptr<MaterialBroker> getInstance();
//    Material findById(int id); //根据id在数据库中查找对象，返回查找到的对象
    void storeObject(QStringList materials, int noteId); //将实例对象存入数据库
    std::vector<MaterialProxy> getNoteMaterials(int noteId);
    ~MaterialBroker();

private:
    MaterialBroker();//私有构造函数，单例模式

private:
    static std::shared_ptr<MaterialBroker> s_materialBroker;  //代管者实例
    static std::mutex materialBrokerMutex;
};

#endif // MATERIALBROKER_H
