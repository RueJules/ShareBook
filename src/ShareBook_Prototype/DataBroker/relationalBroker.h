#ifndef DATABASE_H
#define DATABASE_H
#include <mariadb/conncpp.hpp>
#include <memory>
#include <string>
//#include"DataBaseBroker.h"


class RelationalBroker
{
public:
    RelationalBroker();
    //void connectDB();
    //void initDataBase();访问远程已经完成建立好的数据库，改操作在此版本不再需要
    sql::ResultSet *query(std::string cmd);
    void insert(std::string cmd);
    void update(std::string cmd);
    void drop(std::string cmd); //从数据库中删除

private:

    std::unique_ptr<sql::Connection> m_conn;
};

#endif // DATABASE_H

