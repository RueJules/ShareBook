/*Auther:GongYanxian
Date:2023.6.19*/
#ifndef NOTEINTERFACE_H
#define NOTEINTERFACE_H
class MaterialProxy;
class NoteInterface {

public:
    NoteInterface(int id);
    virtual void addMaterial(int materialId, MaterialProxy &&material)=0;//添加新的消息
    int get_Id();
private:
    int m_id;


};

#endif
