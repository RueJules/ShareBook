/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include "Control.h"
#include "../DataBroker/NetizenBroker.h"
#include <QFileDialog>


void Control::init(int id=1, QString password="123456")
{
    std::shared_ptr netizen=NetizenBroker::getInstance(); //单例broker
    //m_localNetizen=netizen->matchAccount(id,password);
    netizen->matchAccount(id,password);//访问数据库读取网民，会获取网民所有信息，包括的粉丝列表，关注者列表....的一个json文件。然后用文件的内容来创建对象
    //m_localNetizen实例化
    m_localNetizenProxy=new NetizenProxy(local_netizen); //生成网民代理
}

void Control::sendMessage() {
    QList fans=m_netizen->get_fanIdList();
    for(auto fan:fans){
        QDate date = new QDate();
        Message message=new Message(date, m_localNetizen->get_id(),"发布笔记", fan);
        /*to-do
         * 把这条消息写入数据库消息表中
        */
    }
    //m_localNeitizenProxy.sendMessage(message);
}

int Control::createNote(QString title, QString text, std::vector<Material> metrial, int blogger)//从ui传来的用户输入的笔记数据，现在不做，现在是选择一个文件（一个txt文本文件和几个图片文件）
{
    //使用文件管理器进行文件的选择组成一个笔记

    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(QStringLiteral("选择文件"));
    fileDialog->setDirectory("../ShareBook_Prototype/test_file");
    fileDialog->setNameFilter(tr("File(*.txt* *.jpg* *.png* *.svg*)"));
    //设置可以选择多个文件
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //获取选择的文件的路径
    QStringList fileNames;
    if (fileDialog->exec()) {
        fileNames = fileDialog->selectedFiles();
    }

    //将笔记的内容装进数据库

    //emit 完成笔记发
    //通知粉丝有新的笔记，可能是信号与槽的机制实现
     sendMessage();

    //新建一个笔记实例，插入网民实例的发布的笔记的列表里，有可能也是发送一个信号，由NetizenProxy接收

    //更新网民在数据库中的信息
}
