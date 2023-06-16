#ifndef NETIZENPROXY_H
#define NETIZENPROXY_H

class NetizenProxy : NetizenInterface {

public:
	Netizen* m_netizen;

	json getAbstract(string netizenId);

	void sendMessage(string Id);

	void receiveMessage();

	void initAccount(string netizenId);

	json getDetails(string netizenId);
};

#endif
