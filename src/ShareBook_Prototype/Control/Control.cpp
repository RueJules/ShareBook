/*
 * datetime:2023-6-17
 * author:chenzexi
*/
#include "Control.h"
#include "../DataBroker/NetizenBroker.h"
#include <QFileDialog>


void Control::init(string id=1,string password=123456)
{
    std::shared_ptr netizen=NetizenBroker::getInstance();
    m_localNetizen=netizen->matchAccount(id,password);
    m_localNetizenProxy=new NetizenProxy(local_netizen);
}

void Control::sendMessage() {

    Message message=new Message(m_localNetizen->get_id(),"发布笔记");
    m_localNeitizenProxy.sendMessage(message);
}

int Control::createNote(string title, string text, vector<Metrial> metrial, vector<string> keyword, string blogger)//从ui传来的用户输入的笔记数据，现在不做，现在是选择一个文件（一个txt文本文件和几个图片文件）
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

    //新建一个笔记实例，插入网民实例的发布的笔记的列表里

    //更新网民在数据库中的信息
}
