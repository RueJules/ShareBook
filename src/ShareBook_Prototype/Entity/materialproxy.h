/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MATERIALPROXY_H
#define MATERIALPROXY_H

#include"Material.h"

class MaterialProxy
{
public:
    MaterialProxy();
    MaterialProxy(Material* material);
    void setMaterial(Material mtr);
    //void preview()

private:
    Material* _material; //持有一个素材实例
};

#endif // MATERIALPROXY_H
