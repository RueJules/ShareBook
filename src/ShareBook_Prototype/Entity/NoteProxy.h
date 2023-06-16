#ifndef NOTEPROXY_H
#define NOTEPROXY_H

class NoteProxy : NoteInterface {

public:
	Note* m_note;

	json getAbstract();
};

#endif
