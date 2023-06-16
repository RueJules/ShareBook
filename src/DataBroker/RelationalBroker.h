#ifndef RELATIONALBROKER_H
#define RELATIONALBROKER_H

class RelationalBroker : DataBaseBroker {

public:
	unique_ptr<sql::Connection> m_connection;

	void initDataBase();

	sql::ResultSet* query(string cmd);

	void insert(string cmd);

	virtual void update() = 0;

	void drop(string cmd);
};

#endif
