import QtQuick
import Qt5Compat.GraphicalEffects
Item {
    Rectangle{
        anchors.fill: parent
        color:"#009688"
        GridView {
            id:grid
            anchors.fill: parent
            model: ListViewModel
            leftMargin:5
            cellWidth: (parent.width-grid.leftMargin)/2
            cellHeight:parent.height*2/5

            delegate: Rectangle {
                property int id_:note_id
                radius: 10
                width: grid.cellWidth-5
                height:grid.cellHeight-5
                //OpacityMask使用时用到的rectangle和image必须在同一层级
                Image {
                    id: material
                    source: firstImg===""?"qrc:/resource_file/materials/2991e08f0e0926a5424c8cb73bca7742.png":qsTr(firstImg)
                    width: parent.width
                    height:parent.height-115
                    fillMode: Image.PreserveAspectFit //缩放以适应屏幕
                    visible: false

                }
                Rectangle {
                    id: mask
                    color: "black"
                    radius: 10
                    width: grid.cellWidth-5
                    height:grid.cellHeight-5
                    visible: false
                }
                OpacityMask {
                    anchors.fill: material
                    source: material
                    maskSource: mask
                    visible: true
                }
                Rectangle{
                    id:titleRec
                    width: parent.width
                    height:60
                    anchors.top:material.bottom
                    Text {
                        id: titleText
                        width: parent.width
                        anchors.verticalCenter:titleRec.verticalCenter
                        text: qsTr(title)
                        padding: 10
                        wrapMode:Text.Wrap
                        font.pixelSize: 18
                    }
                }
                Image {
                    id: profileImg
                    source: qsTr(profile)
                    width: 50
                    height: 50
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                    anchors.top:titleRec.bottom
                    visible: false
                }
                Rectangle {
                    id: _mask
                    color: "black"
                    width: 50
                    height: 50
                    radius: 50
                    anchors.top:titleRec.bottom
                    visible: false
                }
                OpacityMask {
                    anchors.fill: profileImg
                    source: profileImg
                    maskSource: _mask
                    visible: true
                }
                Rectangle{
                    id:nickRec
                    height: 50
                    anchors.left: profileImg.right
                    anchors.top:titleRec.bottom
                    Text {
                        id: nicknameText
                        text: qsTr(nickname)
                        padding: 10
                        font.pixelSize: 18
                        anchors.verticalCenter:nickRec.verticalCenter
                    }
                }
                TapHandler{
                    onTapped: {
                        var detail_data=[profile,nickname,title,content,time,id_,material.source]
                        stack.push("NoteDetailPage.qml",{"data":detail_data})
                    }
                }
            }
        }
    }
}
