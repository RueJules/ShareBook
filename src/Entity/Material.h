#ifndef MATERIAL_H
#define MATERIAL_H

class Material : MaterialInterface {

private:
	ByteArray m_image;
	string m_identifier;

public:
	ByteArray get_image();

	void set_image(ByteArray m_image);
};

#endif
