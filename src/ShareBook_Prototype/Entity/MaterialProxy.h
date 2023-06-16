#ifndef MATERIALPROXY_H
#define MATERIALPROXY_H

#include "Material.h"

class MaterialProxy : MaterialInterface {

public:
	Material m_material;

	void preview();
};

#endif
