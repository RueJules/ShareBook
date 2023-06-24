/*Auther:GongYanxian
Date:2023.6.19*/
#include "noteBroker.h"
//#include "materialbroker.h"
#include<iostream>
std::shared_ptr<NoteBroker> NoteBroker::s_noteBroker = nullptr;
std::mutex NoteBroker::noteBrokerMutex;
NoteBroker::NoteBroker()
{

}
NoteBroker::~NoteBroker()
{

}

std::shared_ptr<NoteBroker> NoteBroker::getInstance()
{
    if(s_noteBroker == nullptr){
        std::unique_lock<std::mutex> lock(noteBrokerMutex);
        if(s_noteBroker==nullptr){
            auto temp = std::shared_ptr<NoteBroker>(new NoteBroker());
            s_noteBroker = temp;
        }
    }
    return s_noteBroker;

}


//Note* NoteBroker::findById(int noteId) {
//	// TODO - implement NoteBroker::findById
//    std::string query1 = "select * from note where id = " + std::to_string(noteId);  //通过id在数据库中找到这个笔记的所有信息
//    sql::ResultSet *resSet1 = query(query1);
//    if(resSet1 == nullptr){
//        std::cerr << "未找到笔记";
//        return nullptr;
//    }
//    std::string title = resSet1->getString("title").c_str();
//    std::string text = resSet1->getString("text").c_str();
//    int materialCount = resSet1->getInt("materials");
//    int bloggerId = resSet1->getInt("blogger");
//    std::string time = resSet1->getString("time").c_str();
//    Note newNote(noteId, bloggerId,  title,  text, findMaterials(noteId), materialCount,time); //没有返回值？？应该new一个对象吧
//}

int NoteBroker::storeObject(std::string title, std::string content, int materialsCount,std::string imgsrc,QDateTime time ,int bloggerID) {
    //在数据库中插入笔记
    std::string insert_cmd = "insert into note(title,content,materials,firstImg,time,blogger) values(\""
                      +title+"\",\""+content+"\","+std::to_string(materialsCount)+",\""+imgsrc+"\",\""+
                      time.toString("yyyyMMddhhmmss").toStdString()+"\","+std::to_string(bloggerID)+")";
//    qDebug()<<insert_cmd;
    insert(insert_cmd);

    //返回新插入笔记的自增id
    int noteID;
    std::string query_cmd = "select last_insert_id()from note";
    sql::ResultSet* res = query(query_cmd);
    if(res->next()){
        noteID=res->getInt(1);
    }
    return noteID;
}

//std::vector<int> NoteBroker::findMaterials(int id)
//{
//    std::string cmd = "select *from material where note_id=" + std::to_string(id);
//    sql::ResultSet* res = query(cmd);
//    std::vector<int> materials;
//    while(res->next()){
//        materials.push_back(res->getInt("id"));
//    }
//    return fans;
//}
sql::ResultSet *NoteBroker::getNotes(int netizenId)
{
    std::string query1 = "select note.* ,netizen.nickname ,netizen.profile_photo from note,netizen where note.blogger<> "+std::to_string(netizenId)+" and note.blogger=netizen.id  order by note.time DESC limit 0,10";
    return query(query1);
}


