#ifndef MYLISTVIEWMODEL_H
#define MYLISTVIEWMODEL_H
#include"../Entity/note.h"
#include <QObject>
#include <QDebug>
#include <QAbstractListModel>
#include<iostream>
#include <mariadb/conncpp.hpp>
using namespace std;

class MyListViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MyListViewModel(QObject *parent = nullptr);
    std::unique_ptr<Note> findNoteInfoInModel(int noteId);//ui传一个笔记的id回来，然后在map列表中找之前存放的笔记的信息，返回相关信息用来在control中生成一个笔记实例

    // 这几个函数必须要重写
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // 然后再添加几个，可以操作model的函数
    Q_INVOKABLE void append(sql::ResultSet*resultSet);
    Q_INVOKABLE void remove(int index);


private:
    enum DataRoles{//当视图View向模型Model索要数据时，不仅要提供索引 index，还必须要提供角色role。index和role共同
                    //决定出视图到底在向Model请求哪个数据
        IDRole= Qt::UserRole + 1,
        NickNameRole,
        ProfileRole,
        TitleRole,
        ContentRole,
        FirstMateriaRole,
        TimeRole
    };

    struct Data{
        int note_id;
        int blogger_id;
        string nickname;
        string profile;
        string title;
        string content;
        string firstMaterial;
        int materialCount;
        string time;
    };
    QList<Data> dataList;
};

#endif // MYLISTVIEWMODEL_H
