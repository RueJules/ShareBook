/*Auther:GongYanxian
Date:2023.6.19*/
#ifndef NOTEPROXY_H
#define NOTEPROXY_H
#include "note.h"
class NoteProxy : public NoteInterface {

public:

    NoteProxy(int id);
    NoteProxy(int id,std::unique_ptr<Note>&& note);


//	json getAbstract();

private:
     std::unique_ptr<Note> m_note;
};

#endif
