/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MATERIAL_H
#define MATERIAL_H
#include <QByteArray>
#include "materialinterface.h"

class Material : MaterialInterface {

public:
    Material();
    Material(QByteArray img, int order);

    QByteArray get_image();  //获取当前素材的内容
    void set_image(QByteArray image);

private:
    QByteArray m_image; //当前素材的内容（图片）
    int number; //图片所属顺序


};

#endif
