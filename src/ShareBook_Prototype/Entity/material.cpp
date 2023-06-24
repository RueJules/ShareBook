/*Auther:Huangyihong
Date:2023.6.17*/

#include "material.h"

Material::Material(int id, QPixmap imgsrc, int order):MaterialInterface(id),m_imgsrc{imgsrc},m_order{order}
{

}

//QByteArray Material::get_image() {
//	// TODO - implement Material::get_image
//	throw "Not yet implemented";
//}

//void Material::set_image(QByteArray image) {
//	// TODO - implement Material::set_image
//	throw "Not yet implemented";
//}
