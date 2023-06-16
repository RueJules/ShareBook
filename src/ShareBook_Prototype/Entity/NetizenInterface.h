#ifndef NETIZENINTERFACE_H
#define NETIZENINTERFACE_H

class NetizenInterface {

private:
	string m_id;

public:
	void addNote(string noteId, NoteProxy note);

	void addFan(string fanId, NetizenProxy fan);

	void addConcern(string concernId, NetizenProxy concern);

	string get_id();
};

#endif
