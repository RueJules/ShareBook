#include "database.h"
#include <iostream>

DataBase::DataBase()
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

/*void DataBase::connectDB()
{
//    //安装驱动
//    sql::Driver* driver = sql::mariadb::get_driver_instance();

//    //配置连接
//    sql::SQLString url("jdbc:mariadb://localhost:3306/todo");
//    sql::Properties properties({{"user", "app_user"}, {"password", "Password123!"}});

//    //建立连接
//    std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
//    m_conn=std::move(conn);
}*/

void DataBase::insert()
{
    try{
    // Create a new PreparedStatement
    std::unique_ptr<sql::PreparedStatement> stmnt(m_conn->prepareStatement("insert into netizen(nickname,profile_photo,concerns,fans,messages) values ('龚颜鲜', 'profile_photo', 1, 2, 3)"));

    // Bind values to SQL statement
//    stmnt->setString(1, des);

    // Execute query
    stmnt->executeQuery();
    }catch(sql::SQLException& e){
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
}
