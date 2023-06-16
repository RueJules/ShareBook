#ifndef NOTEBROKER_H
#define NOTEBROKER_H

class NoteBroker : DataBaseBroker {


public:
	Note findById(string noteId);

	void storeObject(Note note);
};

#endif
