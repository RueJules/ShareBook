#include "Note.h"
/*
 * 	string m_blogger;
    string m_title;
    string m_text;
    vector<Material> m_materials;
    vector<string> m_keyword;
    QDateTime m_time;
 */
Note::Note(int id, int blogger, std::string title, std::string text, std::vector<Material> materials, int material,QDateTime time)
    :NoteInterface(id),m_blogger{blogger},m_title{title},m_text(text), m_material{material}, m_materials{materials},m_time{time}
{

}

int Note::get_blogger() {
	// TODO - implement Note::get_blogger
	throw "Not yet implemented";
    return m_blogger;
}

std::string Note::get_title() {
	// TODO - implement Note::get_title
	throw "Not yet implemented";
    return m_title;
}

std::string Note::get_text() {
	// TODO - implement Note::get_text
	throw "Not yet implemented";
    return m_text;
}

std::vector<Material> Note::get_materials() {
	// TODO - implement Note::get_materials
	throw "Not yet implemented";
    return m_materials;
}

//std::vector<string> Note::get_keyword() {
//    // TODO - implement Note::get_keyword
//    throw "Not yet implemented";
//    return m_keyword;
//}

QDateTime Note::get_time()
{
    return m_time;
}

