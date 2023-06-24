/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MATERIALPROXY_H
#define MATERIALPROXY_H

#include"material.h"

class MaterialProxy: public MaterialInterface
{
public:
    MaterialProxy(int id);
    MaterialProxy(int id,std::unique_ptr<Material> &&material);
    //MaterialProxy(const MaterialProxy&mp);
//    void setMaterial(Material &mtr);
    //void preview()

private:
    std::unique_ptr<Material> m_material; //持有一个素材实例
};

#endif // MATERIALPROXY_H
