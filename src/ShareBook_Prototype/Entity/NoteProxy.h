#ifndef NOTEPROXY_H
#define NOTEPROXY_H
#include "Note.h"
class NoteProxy : NoteInterface {

public:
    NoteProxy(Note &note);

	json getAbstract();

private:
    Note* m_note;
};

#endif
