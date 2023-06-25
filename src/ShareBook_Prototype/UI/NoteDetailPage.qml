import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id:pge
    property alias d_profile: detail_profile.source
    property alias d_nickname: nickname.text
    property alias d_content: contentArea.text
    property alias d_title: titleArea.text
    property alias d_time: note_time.text
    property alias d_id: pge.checked_noteId

    property int checked_noteId
    visible: true
    header:Item{
        id:itm
        width: root.width
        height: root.height/20
        RowLayout {
            id:row
            Button{
                id:btn
                Layout.maximumHeight: itm.height
                Layout.minimumHeight: itm.height
                Layout.maximumWidth: itm.height
                Layout.minimumWidth: itm.height
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.rightMargin: 5
                flat: true
                icon.source: "qrc:/UI/icon/return.svg"
                icon.width: itm.height * 0.7
                icon.height: itm.height * 0.7
                onClicked: {
                    stack.clear()
                }
            }
            Rectangle{
                id:rec
//                width: 45
//                height:45
                Layout.maximumHeight: itm.height
                Layout.minimumHeight: itm.height
                Layout.maximumWidth: itm.height
                Layout.minimumWidth: itm.height
                Image {
                    id:detail_profile
                    anchors.fill: parent
                }
            }
            Text{
                id:nickname
                Layout.leftMargin: 5
            }
            Button{
                id:gofollow
                Layout.leftMargin: itm.width - itm.height*5.5
                flat: true
                height: itm.height
                text: qsTr("follow")
                contentItem: Text {
                       id: text2
                       font: gofollow.font
                       text: gofollow.text
                       color: "red"
                       horizontalAlignment: Text.AlignHCenter
                       verticalAlignment: Text.AlignVCenter
                   }
                background: Rectangle{
                    id:bgd
                    implicitWidth: itm.height*1.7
                    implicitHeight: itm.height * 0.7
                    border.color: "red"
                    radius: 20
                }
                onClicked: {
                    text2.text = text2.text === "follow" ? "followed" : "follow"
                }
            }
        }
    }

    ScrollView{
        id:sv
        anchors.fill: parent
        anchors.topMargin: 3
        contentHeight: view.height + indicator.height + titleArea.height + contentArea.height + note_time.height + pge.height*0.2
        //contentWidth: pge.width

        SwipeView {
            id:view
            width: parent.width
            height: 500
            //anchors.fill:parent
            Repeater{
                model:control.getNoteDetails(5)  //c++端传来的素材路径
                Image{
                    fillMode: Image.PreserveAspectFit
                    source:modelData
                }
            }

            }
            PageIndicator {
                id: indicator
                count: view.count
                currentIndex: view.currentIndex
                anchors.top: view.bottom
                anchors.topMargin: 5
                anchors.horizontalCenter: parent.horizontalCenter
            }


        Text{
                id:titleArea
                width: root.width
                anchors.top: indicator.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.topMargin: 5
                font.bold: true
                font.pointSize: 12
                wrapMode:Text.Wrap
            }

        Text{
                id:contentArea
                anchors.top: titleArea.bottom
                anchors.topMargin: 5
                anchors.left: parent.left
                anchors.right: parent.right
                wrapMode:Text.Wrap

            }
        Text{
                id:note_time
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: contentArea.bottom
                anchors.topMargin: 5
                font.family: "Courier"
                font.bold: true
                font.pointSize: 8
                wrapMode:Text.Wrap
        }
    }

}
