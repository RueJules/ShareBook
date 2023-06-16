#ifndef MESSAGEPROXY_H
#define MESSAGEPROXY_H

class MessageProxy : MessageInterface {

public:
	Message* m_message;

	void getMessage();
};

#endif
