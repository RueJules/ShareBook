#ifndef MESSAGEBROKER_H
#define MESSAGEBROKER_H

class MessageBroker : DataBaseBroker {


public:
	Message findById(string Id);

	void storeObject(Message message);
};

#endif
