#include "NoteBroker.h"
#include "materialbroker.h"

Note NoteBroker::findById(int noteId) {
	// TODO - implement NoteBroker::findById
    QString query1 = "select * from note where id = " + std::to_string(noteId);  //通过id在数据库中找到这个笔记的所有信息
    sql::ResultSet *resSet1 = query(query);
    if(resSet1 == nullptr){
        std::cerr << "未找到笔记";
    }
    QString title = resSet1->getString("title");
    QString text = resSet1->getString("text");
    int materialCount = resSet1->getString("materials");
    int bloggerId = resSet1->getString("blogger");
    Note newNote(noteId,bloggerId, title, text, materialCount, findMaterials(noteId), new QDateTime());

}

void NoteBroker::storeObject(Note note) {
    // TODO - implement NoteBroker::storeObject
    throw "Not yet implemented";
}

std::vector<int> NoteBroker::findMaterials(int id)
{
    QString cmd = "select *from material where note_id=" + std::to_string(id);
    sql::ResultSet res = query(cmd);
    std::vector<int> fans;
    while(res.next()){
        fans.push_back(res.getString("id"));
    }
    return fans;
}

std::shared_ptr<NoteBroker> NoteBroker::getInstance()
{
    if(s_noteBroker == nullptr){
        noteBrokerMutex.lock();
        s_noteBroker = new NoteBroker();
        return s_noteBroker;
    }else{
        return s_noteBroker;
    }

}

void NoteBroker::deleteInstance()
{

}

