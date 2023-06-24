/*Auther:Huangyihong
Date:2023.6.17*/

#include "materialProxy.h"


MaterialProxy::MaterialProxy(int id):MaterialInterface{id},m_material{nullptr}
{

}
MaterialProxy::MaterialProxy(int id, std::unique_ptr<Material>&&material):MaterialInterface{id},m_material{std::move(material)}
{

}
//MaterialProxy::MaterialProxy(const MaterialProxy&mp):MaterialInterface{mp.m_id},m_material{std::move(mp.m_material)}{
//}


