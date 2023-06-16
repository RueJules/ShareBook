#ifndef NETIZEN_H
#define NETIZEN_H

class Netizen : NetizenInterface {

private:
	std::vector<Netizen> fan;
	std::vector<Netizen> concern;
	string m_password;
	string m_nickName;
	ByteArray m_profileImage;
	unorder_map<string, NoteProxy> m_pulishNoteList;
	unorder_map<string, NetizenProxy> m_fanList;
	unorder_map<string, NetizenProxy> m_concernList;
	unordered_map<string, MessageProxy> m_messageList;
	bool m_newNoteMessage;

public:
	string get_nickName();

	ByteArray get_profileImage();

	vector<string> get_pulishNoteIdList();

	vector<string> get_fanIdList();

	vector<string> get_concernIdList();

	void addMessage(string megId, MessageProxy message);
};

#endif
