/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MATERIALBROKER_H
#define MATERIALBROKER_H
#include "../Entity/Material.h"
#include "RelationalBroker.h"


class MaterialBroker : public RelationalBroker
{
public:
    static MaterialBroker instance();
    Material findById(int id); //根据id在数据库中查找对象，返回查找到的对象
    void storeObject(Material material); //将实例对象存入数据库

private:
    MaterialBroker();//私有构造函数，单例模式

private:
    MaterialBroker instance;  //代管者实例
};

#endif // MATERIALBROKER_H
