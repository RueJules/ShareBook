/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MATERIAL_H
#define MATERIAL_H
#include <QByteArray>
#include<QPixmap>
#include "materialInterface.h"

class Material : public MaterialInterface {

public:
    Material(int id,QPixmap imgsrc, int order);

//    QByteArray get_image();  //获取当前素材的内容
//    void set_image(QByteArray image);

private:
    QPixmap m_imgsrc; //当前素材的内容（图片）
    int m_order; //图片所属顺序
};

#endif
