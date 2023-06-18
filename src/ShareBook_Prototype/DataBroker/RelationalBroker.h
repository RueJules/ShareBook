#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <mariadb/conncpp.hpp>
#include <memory>
//#include"DataBaseBroker.h"


class RelationalBroker
{
public:
    RelationalBroker();
    //void connectDB();
    //void initDataBase();访问远程已经完成建立好的数据库，改操作在此版本不再需要
    sql::ResultSet *query(QString cmd);
    void insert(QString cmd);
    void update(QString cmd);
    void drop(QString cmd); //从数据库中删除

private:

    std::unique_ptr<sql::Connection> m_conn;
};

#endif // DATABASE_H

