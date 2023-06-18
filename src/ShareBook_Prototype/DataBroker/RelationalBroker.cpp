#include "RelationalBroker.h"
#include <iostream>

RelationalBroker::RelationalBroker()
{
    //安装驱动
    sql::Driver* driver = sql::mariadb::get_driver_instance();

    //配置连接
    sql::SQLString url("jdbc:mariadb://10.252.65.98:3306/ShareBook");
    sql::Properties properties({{"user", "netizen"}, {"password", "12345678"}});

    //建立连接
    std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
    m_conn=std::move(conn);
}

sql::ResultSet* RelationalBroker::query(std::string cmd)
{
    try{
        std::unique_ptr<sql::PreparedStatement> stmntQ(m_conn->prepareStatement(cmd));
        sql::ResultSet *res = stmntQ->executeQuery(cmd);
        return res;

    }catch(sql::SQLException &e){
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
    return nullptr;
}

void RelationalBroker::insert(std::string cmd)
{
    try{
    // Create a new PreparedStatement
    std::unique_ptr<sql::PreparedStatement> stmnt(m_conn->prepareStatement(cmd));

    // Bind values to SQL statement
   //    stmnt->setString(1, des);

    // Execute query
    stmnt->executeQuery();
    }catch(sql::SQLException& e){
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
}

void RelationalBroker::update(std::string cmd)
{
    try{
        // Create a new PreparedStatement
        std::unique_ptr<sql::PreparedStatement> stmnt(m_conn->prepareStatement(cmd));

        // Execute query
        stmnt->executeQuery();

    }catch(sql::SQLException& e){
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
}

void RelationalBroker::drop(std::string cmd)
{
    try{
        // Create a new PreparedStatement
        std::unique_ptr<sql::PreparedStatement> stmnt(m_conn->prepareStatement(cmd));

        // Execute query
        stmnt->executeQuery();
    }catch(sql::SQLException& e){
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
}


/*void DataBase::connectDB()
{

}*/
