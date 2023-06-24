#include "note.h"

Note::Note(int id, std::string title, std::string content, int materialCount,std::string imgsrc,QDateTime time,int blogger):NoteInterface{id},m_title{title},m_content{content},m_materialCount{materialCount},m_firstImgsrc{imgsrc},m_time{time},m_bloggerId{blogger}
{

}

int Note::get_blogger() {
	// TODO - implement Note::get_blogger
	throw "Not yet implemented";
    return m_bloggerId;
}

std::string Note::get_title() {
	// TODO - implement Note::get_title
	throw "Not yet implemented";
    return m_title;
}

std::string Note::get_content() {
	// TODO - implement Note::get_text
	throw "Not yet implemented";
    return m_content;
}
QDateTime Note::get_time()
{
    return m_time;
}
void Note::addMaterial(int materialId, MaterialProxy &&material)
{
    m_materials.emplace(materialId,std::move(material));
}

//std::vector<int> Note::get_materials() {
//	// TODO - implement Note::get_materials
//	throw "Not yet implemented";

//    return m_materials;
//}

//std::vector<string> Note::get_keyword() {
//    // TODO - implement Note::get_keyword
//    throw "Not yet implemented";
//    return m_keyword;
//}


