/*
 * datetime:2023-6-17
 * author:chenzexi
*/

#include <QFileDialog>
#include <QWidget>
#include <memory>
#include "control.h"
#include "../DataBroker/netizenBroker.h"
#include "../Entity/netizen.h"
#include "../DataBroker/noteBroker.h"
#include "../DataBroker/materialBroker.h"


std::unique_ptr<NetizenProxy> Control::s_localNetizenProxy=nullptr;

void Control::init(int id, std::string password)
{
    //model=new MyListViewModel();
    std::unique_ptr<Netizen> localNetizen=std::make_unique<Netizen>();
    NetizenBroker::getInstance()->matchAccount(id,password,*localNetizen);//访问数据库读取网民，会获取网民所有信息，包括的粉丝列表，关注者列表....的一个json文件。然后用文件的内容来创建对象
    //读取成功
    if(localNetizen->id()){
        s_localNetizenProxy=std::make_unique<NetizenProxy>(localNetizen->id(),std::move(localNetizen));
    }
    s_localNetizenProxy->getDetails();
}

void Control::requestPublish()//从ui传来的用户输入的笔记数据，现在不做，现在是选择一个文件（一个txt文本文件和几个图片文件）
{
    //使用文件管理器进行文件的选择组成一个笔记
    QStringList fileNames=QFileDialog::getOpenFileNames(nullptr,tr("选择文件"), "../file_material",
                                                                    tr("File(*.txt* *.jpg* *.png* *.svg*)"),nullptr,QFileDialog::DontUseNativeDialog	);

    //解析文件内容，分离出标题和文本内容，从fileNames中找到文本文件和图片文件
    //文本的路径列表
    QString textFile;
    //素材的路径列表
    QStringList materials;
    //区分文本文件和图片文件
    for(auto filename:fileNames){
        if(filename.right(3) == "txt"){
            textFile = filename;
        }else{
            materials.push_back(filename);
        }
    }
    //读文本文件
    QFile file(textFile);
    std::string  title;
    std::string  text;
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream ts(&file);
        title= ts.readLine().simplified().toStdString();  //读取标题，如果标题那一行没有内容返回的是一个空字符
        text = ts.readAll().simplified().toStdString(); //消除换行符
        file.close();
        qDebug()<<title<<text;
    }
    //读素材文件
    int count=0;
    std::string  firstImg;
    if(materials.size()){
        count=materials.size();
        firstImg=materials[0].toStdString();
    }

    //获取笔记的发布时间
    QDateTime time=QDateTime::currentDateTime();

    //将笔记存入数据库
    int  noteId=NoteBroker::getInstance()->storeObject(title, text,count,firstImg,time,s_localNetizenProxy->id());
    //更新网民发布笔记对应的数据库表
    NetizenBroker::getInstance()->updatePublishNote(s_localNetizenProxy->id(),noteId);

    //把笔记对应的素材存入数据库的素材表
    if(count)
        MaterialBroker::getInstance()->storeObject(materials, noteId);  //素材顺序由容器数组下标获取
    //创建note实例
    //创建一个笔记对象
    std::unique_ptr<Note>note = make_unique< Note>(noteId,title, text, count,firstImg,time,s_localNetizenProxy->id());
    NoteProxy noteProxy(noteId,std::move(note));
    //更新网民实例的发布笔记列表
    s_localNetizenProxy->addNote(noteId,std::move(noteProxy));
    //有粉丝就通知粉丝发了新消息
    if(s_localNetizenProxy->fansCount())
        s_localNetizenProxy->sendMessage("发布了一条笔记");
}

void Control::getNotes()
{
    sql::ResultSet *res=NoteBroker::getInstance()->getNotes(s_localNetizenProxy->id());
    model->append(res);
}

void Control::getNoteDetails(int noteId)
{
    //创建一个笔记对象
    std::unique_ptr<Note> note=model->findNoteInfoInModel(noteId);
    NoteProxy noteProxy(noteId,std::move(note));
    std::vector<MaterialProxy> materials = MaterialBroker::getInstance()->getNoteMaterials(noteId);

    for(int i=0;i<materials.size();i++){
        noteProxy.addMaterial(materials[i].get_id(), std::move(materials[i]));
        qDebug()<<materials[i].get_id();
    }

    //更新网民实例的浏览笔记列表
    s_localNetizenProxy->addFootMark(noteId, std::move(noteProxy));
    NetizenBroker::getInstance()->updateCheckNote(s_localNetizenProxy->id(), noteId);


}
void Control::getPublishNotes()
{
//    int bloggerId = s_localNetizenProxy->id();
//    std::string cmd = "select * from note where blogger = "+std::to_string(bloggerId);
//    //getNoteAbstract(bloggerId)
//    sql::ResultSet *res = NoteBroker::getInstance()->query(cmd);
//    while(res->next()){
//        m_titles.append(res->getString("title").c_str());
//        m_texts.append(res->getString("text").substr(0, 10).c_str());
//    }
//    for(int i = 0; i < m_titles.size(); i++){
//        qDebug() << m_titles[i] <<"--------------" << m_texts[i];
//    }
}
