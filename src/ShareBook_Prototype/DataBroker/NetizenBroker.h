#ifndef NETIZENBROKER_H
#define NETIZENBROKER_H

class NetizenBroker : DataBaseBroker {


public:
	Netizen findById(string Id);

	void updateObject(Netizen netizen);
};

#endif
