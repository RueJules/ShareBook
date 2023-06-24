/*Auther:GongYanxian
Date:2023.6.19*/
#ifndef NOTE_H
#define NOTE_H
#include"noteInterface.h"
#include<QDateTime>
#include<string>
#include"materialProxy.h"
class Note :public NoteInterface {

private:
    int m_bloggerId; //博主id
    std::string m_title;
    std::string m_content;
    QDateTime m_time;
    int m_materialCount;
    std::string m_firstImgsrc;//浏览笔记、查看发布的笔记时（所有看数据库的地方）读取第一张素材的路径把素材实例化放入素材列表中
    std::unordered_map<int, MaterialProxy> m_materials;//初始化为空，点击查看详情时再加入列表中

    //std::vector<std::string> m_keyword;


public:
    Note(int id, std::string title, std::string content, int materialCount,std::string imgsrc,QDateTime time,int blogger);//从数据库读取数据生成笔记
    int get_blogger();  //获得改条博主的id
    std::string get_title(); //获取笔记标题
    std::string get_content();//获取文本
    QDateTime get_time(); //获取笔记发布时间
    void addMaterial(int materialId,MaterialProxy&& material)override;
//    std::vector<int> get_materials(); //获取素材
    //std::vector<string> get_keyword();先不做了



};

#endif
