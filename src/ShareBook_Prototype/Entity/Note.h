#ifndef NOTE_H
#define NOTE_H

class Note : NoteInterface {

private:
	string m_blogger;
	string m_title;
	string m_text;
	vector<Material> m_materials;
	vector<string> m_keyword;
	DateTime m_time;

public:
	string get_blogger();

	string get_title();

	string get_text();

	vector<Material> get_materials();

	vector<string> get_keyword();

	DateTime get_time();
};

#endif
