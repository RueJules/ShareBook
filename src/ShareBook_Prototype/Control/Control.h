#ifndef CONTROL_H
#define CONTROL_H

class Control {


public:
	void sendMessage();

	void createNote(string title, string text, vector<Metrial> metrial, vector<string> keyword, string blogger);
};

#endif
