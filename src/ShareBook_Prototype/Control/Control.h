/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef CONTROL_H
#define CONTROL_H
#include "../Entity/Netizen.h"
#include "../Entity/Material.h"
#include <vector>

class Control {

public:
    void init(int id=1,QString password="123456");//初始化用户信息(从边界类获取输入的信息，此时只使用默认)
	void sendMessage();

    //int createNote(QString title, QString text, std::vector<Material> metrial, std::vector<QString> keyword, int blogger);//返回创建的笔记的id

    int createNote(QString title, QString text, std::vector<Material> metrial, int blogger);

private:
    static Netizen m_localNetizen;//当前登陆的网民，可以用单例模式？？好像也不用多线程操作才用单例，这时候只会有一个线程创建netizen,那也只有一个线程创建broker啊？？什么时候用单例模式
    static NetizenProxy m_localNetizenProxy;//当前登陆的网民的代理;
};

#endif
