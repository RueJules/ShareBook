 /*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef CONTROL_H
#define CONTROL_H
#include"../Entity/netizen.h"
#include"../Entity/netizenProxy.h"
#include "../DataBroker/netizenBroker.h"
#include "myListViewModel.h"
#include <vector>
#include <QObject>
class Control:public QObject{
    Q_OBJECT

public:
    Control(MyListViewModel*m):model{m}{}
    ~Control(){delete model;}
    void init(int id=1,std::string password="123456");//初始化用户信息(从边界类获取输入的信息，此时只使用默认)
    Q_INVOKABLE void requestPublish(QString title,QString content,QList<QString>materials);
    Q_INVOKABLE void getNotes();
    Q_INVOKABLE QList<QString> getNoteDetails(int noteId);
    void getPublishNotes();
//    void setModel(MyListViewModel *newModel){
//        model = newModel;
//    }
//    MyListViewModel * getModel(){
//        return model;
//    }
//signals:
//    void modelChanged();
private:

    static std::unique_ptr<NetizenProxy> s_localNetizenProxy;//当前登陆的网民的代理;
    MyListViewModel* model;
//    QList<std::string>m_texts;
//    QList<std::string>m_titles;

};

#endif
