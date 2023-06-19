/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MATERIALINTERFACE_H
#define MATERIALINTERFACE_H


class MaterialInterface
{
public:
    MaterialInterface(int new_id);
    int get_id();

private:
    int m_id; //素材id
};

#endif // MATERIALINTERFACE_H
