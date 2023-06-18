/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#ifndef CONTROL_H
#define CONTROL_H

class Control {


public:
    void init(string id=1,string password=123456);//初始化用户信息(从边界类获取输入的信息，此时只使用默认)
	void sendMessage();

    int createNote(string title="", string text="", vector<Metrial> metrial={}, vector<string> keyword={}, string blogger="");//返回创建的笔记的id

private:
    static Netizen m_localNetizen;//当前登陆的网民，可以用单例模式？？好像也不用多线程操作才用单例，这时候只会有一个线程创建netizen,那也只有一个线程创建broker啊？？什么时候用单例模式
    static NetizenPorxy m_localNetizenProxy;//当前登陆的网民的代理;
};

#endif
