#ifndef MESSAGE_H
#define MESSAGE_H

class Message : MessageInterface {

private:
	Date m_time;
	string m_sender;
	ByteArray m_profileImage;

public:
	virtual string toString() = 0;
};

#endif
