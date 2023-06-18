/*Auther:Huangyihong
Date:2023.6.17*/

#include "Material.h"

Material::Material()
{

}

Material::Material(int id, QByteArray img, int order):MaterialInterface(id)
{

}

QByteArray Material::get_image() {
	// TODO - implement Material::get_image
	throw "Not yet implemented";
}

void Material::set_image(QByteArray image) {
	// TODO - implement Material::set_image
	throw "Not yet implemented";
}
