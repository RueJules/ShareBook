#include "myListViewModel.h"
#include <QDateTime>

MyListViewModel::MyListViewModel(QObject *parent)
{

}

std::unique_ptr<Note> MyListViewModel::findNoteInfoInModel(int noteId)
{
    for(auto data:dataList){
        if(data.note_id==noteId){
            std::unique_ptr<Note>note=make_unique<Note>(data.note_id,data.title,data.content,data.materialCount,data.firstMaterial,QDateTime::fromString(QString::fromStdString(data.time), "yyyyMMddhhmmss"),data.blogger_id);

            return note;
        }
    }

    //如果没找到就抛出异常
}
int MyListViewModel::rowCount(const QModelIndex &parent) const
{
    return dataList.size();
}

QHash<int, QByteArray> MyListViewModel::roleNames() const
{
    // ListView在delegate中，直接使用字符串中标识的名字获取数据
    QHash<int, QByteArray> roles;
    roles[IDRole] = "note_id";
    roles[NickNameRole] = "nickname";
    roles[ProfileRole] = "profile";
    roles[TitleRole] = "title";
    roles[ContentRole] = "content";
    roles[FirstMateriaRole] = "firstImg";
    roles[TimeRole] = "time";
    return roles;
}
QVariant MyListViewModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row < 0 || row >= dataList.size()) {
        return QVariant("null");
    }

    const Data &data = dataList[row];
    switch (role) {
    case IDRole:
        return QVariant(data.note_id);
    case NickNameRole:
        return QString::fromStdString(data.nickname);
    case ProfileRole:
        return QString::fromStdString(data.profile);
    case TitleRole:
        return QString::fromStdString(data.title);
    case ContentRole:
        return QString::fromStdString(data.content);
    case FirstMateriaRole:
        return QString::fromStdString(data.firstMaterial);
    case TimeRole:
        return QString::fromStdString(data.time);
    default:
        return QVariant("null");
    }
}

void MyListViewModel::append(sql::ResultSet *resultSet)
{
    while(resultSet->next()){
        Data data;
        data.note_id = resultSet->getInt(1);
        data.title = resultSet->getString(2).c_str();
        data.content = resultSet->getString(3).c_str();
        data.materialCount = resultSet->getInt(4);
        data.firstMaterial=resultSet->getString(5).c_str();
        data.time=resultSet->getString(6).c_str();
        data.blogger_id=resultSet->getInt(7);
        data.nickname=resultSet->getString(8).c_str();
        data.profile=resultSet->getString(9).c_str();

        // 在增删改查数据时，都需要发送相对应的信号，这样qml才能及时刷新数据
        emit beginInsertRows(QModelIndex(), dataList.size(), dataList.size());
        dataList.append(data);
        emit endInsertRows();
    }


}
void MyListViewModel::remove(int index)
{
    if(index < 0 || index >= dataList.count()) {
        return;
    }

    // 在增删改查数据时，都需要发送相对应的信号，这样qml才能及时刷新数据
    emit beginRemoveRows(QModelIndex(), index, index);
    dataList.removeAt(index);

    emit endRemoveRows();
}

