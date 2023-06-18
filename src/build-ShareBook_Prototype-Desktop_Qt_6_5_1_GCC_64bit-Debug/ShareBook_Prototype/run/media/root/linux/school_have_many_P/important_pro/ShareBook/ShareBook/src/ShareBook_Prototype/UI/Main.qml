import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 1080
    height: 1920
    title: qsTr("享书")

    footer:TabBar {
       // height:150
        id:tabBar
        TabButton {
            Image{
                height: parent.height
                width: parent.height
                anchors.centerIn: parent
                source:"qrc:/image/home.svg"
            }
        }
        TabButton {
            Image{
                height: parent.height
                width: parent.height
                anchors.centerIn: parent
                source:"qrc:/image/plus.svg"
            }
        }
        TabButton {
            Image{
                height: parent.height
                width: parent.height
                anchors.centerIn: parent
                source:"qrc:/image/evil.svg"
            }
        }
    }
    SwipeView {
        id: view
        currentIndex: tabBar.currentIndex
        anchors.fill: parent
        onCurrentIndexChanged: {
            tabBar.currentIndex = currentIndex
        }
            //第一页
            Rectangle{

                color:"red"
            }
            //第二页
            EditDialog{

            }

            //第三页
            Rectangle{

                color:"green"
            }
        }


}
