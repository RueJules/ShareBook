/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MATERIAL_H
#define MATERIAL_H
#include <QByteArray>
#include "materialInterface.h"

class Material : MaterialInterface {

public:
    Material(int id,std::string imgsrc, int order);

//    QByteArray get_image();  //获取当前素材的内容
//    void set_image(QByteArray image);

private:
    std::string m_imgsrc; //当前素材的内容（图片）
    int m_order; //图片所属顺序
};

#endif
