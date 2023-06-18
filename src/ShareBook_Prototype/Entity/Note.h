#ifndef NOTE_H
#define NOTE_H
#include"NoteInterface.h"
#include "Material.h"
#include<vector>
#include<QDateTime>
#include<QString>

class Note : NoteInterface {

private:
    int m_bloggerId; //博主id
    QString m_title;
    QString m_text;
    std::vector<Material> m_materials;
    //std::vector<QString> m_keyword;
    QDateTime m_time;


public:
//    Note(string blogger, string title,string text,vector<Material> materials,vector<string> keyword,QDateTime time);
    Note(int blogger, QString title,QString text,std::vector<Material> materials,QDateTime time);

    int get_blogger();  //获得改条博主的id
    QString get_title(); //获取笔记标题
    QString get_text();//获取文本
    std::vector<Material> get_materials(); //获取素材
    //std::vector<string> get_keyword();先不做了

    QDateTime get_time(); //获取笔记发布时间
};

#endif
