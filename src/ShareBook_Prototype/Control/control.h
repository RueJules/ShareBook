 /*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef CONTROL_H
#define CONTROL_H
#include"../Entity/netizen.h"
#include"../Entity/netizenProxy.h"
#include "../DataBroker/netizenBroker.h"
#include <vector>
#include <QObject>
class Control:public QObject{
    Q_OBJECT

public:
    void init(int id=1,std::string password="123456");//初始化用户信息(从边界类获取输入的信息，此时只使用默认)
    Q_INVOKABLE void requestPublish();//返回创建的笔记的id
    void createNote(int noteId,std::string title, std::string text, int materials,QDateTime time,int bloggerId);

private:

    static std::unique_ptr<NetizenProxy> s_localNetizenProxy;//当前登陆的网民的代理;
    std::shared_ptr<NetizenBroker> netizenbroker;
};

#endif
