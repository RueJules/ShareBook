import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    //Content Area
    Row{
        id:button
        Button{
            text:"发布笔记"
            onClicked:
                control.requestPublish();
        }
        Button{
            text:"浏览笔记"
            onClicked:
                control.getNotes();
        }
    }

    Rectangle{
        width: 640
        anchors.top: button.bottom
        anchors.bottom: parent.bottom
        ListView {
            anchors.fill: parent
            model: ListViewModel

            delegate: Item {
                width: parent.width
                height: 300

                Text {
                    id: nicknameText
                    text: qsTr(nickname)
                    //anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 18

                }

//                Image {
//                    id: profileImg
//                    source: qsTr(profile)
//                    anchors.verticalCenter: parent.verticalCenter
//                    width: 20
//                    height: 20
//                    x: 100
//                }
                Image {
                    id: material
                    source: qsTr(firstImg)
                    //anchors.verticalCenter: parent.verticalCenter
                    width: 50
                    height: 50
                    anchors.top:nicknameText.bottom
                }
                Text {
                    id: titleText
                    text: qsTr(title)
                    //anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 18
                    anchors.top:material.bottom
                }

                Text {
                    id: contentText
                    text: qsTr(content)
                    //anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 18
                    anchors.top:titleText.bottom

                }


                //图片列表
                Text {
                    id: publishTime
                    text: qsTr(time)
                    //anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 18
                    anchors.top:contentText.bottom

                }
            }
        }

    }
}
