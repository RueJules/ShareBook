#include "note.h"

Note::Note(int id, std::string title, std::string text, int materialCount, QDateTime time, int blogger):NoteInterface{id},m_title{title},m_text{text},m_time{time},m_bloggerId{blogger}
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

std::string Note::get_text() {
	// TODO - implement Note::get_text
	throw "Not yet implemented";
    return m_text;
}
QDateTime Note::get_time()
{
    return m_time;
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


