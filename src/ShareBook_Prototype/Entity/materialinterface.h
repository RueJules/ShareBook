/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MATERIALINTERFACE_H
#define MATERIALINTERFACE_H


class MaterialInterface
{
public:
    MaterialInterface(int new_id);
    MaterialInterface();
    int get_id();

private:
    int id; //素材id
};

#endif // MATERIALINTERFACE_H
