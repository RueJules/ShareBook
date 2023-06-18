#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <mariadb/conncpp.hpp>
#include <memory>
#include"DataBaseBroker.h"
class RelationalBroker:public DataBaseBroker
{
public:
    DataBase();
    //void connectDB();
    void insert();
private:
    int id;
    std::string des = "Everday is painful";
    int completed;
    std::unique_ptr<sql::Connection> m_conn;
};

#endif // DATABASE_H

