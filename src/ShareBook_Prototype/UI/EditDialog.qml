import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
import QtQuick.Layouts
Item {
    Rectangle{
        id:title
        color: "#fdfbfb"
        width:parent.width
        height: 60
        anchors.top: parent.top
        Text {
            id: name
            anchors.centerIn: parent
            color:"#596164"
            text: qsTr("发布笔记")
        }
        MyButton{
            id:publish
            background: Rectangle{
                anchors.fill: parent
                radius:10
                color: "#fdfbfb"
            }
            anchors.right: parent.right
            width: 40
            show:"qrc:/UI/icon/checkmark.svg"
            icon_color:"#009688"
            onClicked: {
                control.requestPublish();
            }
        }
        MyButton{
            id:exit
            background: Rectangle{
                anchors.fill: parent
                radius:10
                color: "#fdfbfb"
            }
            anchors.left: parent.left
            width: 40
            show:"qrc:/UI/icon/cross.svg"
            icon_color:"#596164"
            onClicked: {
                stack.clear();
            }
        }
    }
    Rectangle{
        id:background
        width: parent.width
        height: parent.height-60
        anchors.top: title.bottom
        gradient: Gradient {
            GradientStop {  position: 0.0;    color: "#009688"  }
            GradientStop {  position: 1.0;    color: "#FFFBFF" }
//            GradientStop {  position: 0.8;    color: "#f3e7e9" }
//            GradientStop {  position: 1.0;    color: "#fdfbfb" }
        }
        Rectangle{
            id:edit
            width: background.width-20
            height:background.height-10
            radius: 20
            anchors.centerIn: parent
            color: "#fdfbfb"
            ColumnLayout{
                Rectangle{
                    id:box1
                    width: edit.width
                    height: 50
                    opacity: 0
                }
                TextField{
                    id: textfield_1
                    width: edit.width
                    height: 80
                    leftPadding: 15
                    rightPadding: 20
                    //无输入时显示的文本
                    placeholderText: "输入标题（20个字）"
                    placeholderTextColor: "gray"
                    selectByMouse: true
                    //选中文本的颜色
                    selectedTextColor: "white"
                    //选中文本背景色
                    selectionColor: "#009688"
                    font{
                        family: "SimSun"
                        pixelSize: 23
                        bold:true
                    }
                    //设置最多可输入的字符
                    maximumLength:31
                    //截取超出部分
                    clip: true
                    //默认Text.QtRendering看起来比较模糊
                    renderType: Text.NativeRendering
                    background: Rectangle {
                        color: "#fdfbfb"
                    }

                    //信号
                    //长按时会发出此信号（延迟取决于平台插件）
                    onPressAndHold: { /*event*/ }
                    //当用户按下文本字段时，将发出此信号
                    onPressed: {

                    }
                    //当用户释放文本字段时，将发出此信号
                    onReleased: { /*event*/ }
                }
                Rectangle{
                    id:box2
                    width: edit.width
                    height: 60
                    opacity: 0
                }
                Rectangle{
                    id:box3
                    width: edit.width
                    height: 5
                    color: "#fdd6bd"
                    radius: 10
                    //Layout.alignment: Qt.AlignVCenter

                }
                Rectangle{
                    id:box4
                    width: edit.width
                    height: 60
                    opacity: 0
                }
                Rectangle{
                    id:box5
                    width: edit.width
                    height: 400
                    ScrollView {
                        id: view
                        anchors.fill: parent
                        TextArea{
                            id: textfield_2
                            width: edit.width
                            height: contentHeight
                            leftPadding: 15
                            rightPadding: 15
                            //无输入时显示的文本
                            placeholderText: "输入文本内容（300个字）"
                            placeholderTextColor: "gray"
                            selectByMouse: true
                            //选中文本的颜色
                            selectedTextColor: "white"
                            //选中文本背景色
                            selectionColor: "#009688"
                            font{
                                family: "SimSun"
                                pixelSize: 23
                            }
                            wrapMode:TextEdit.Wrap
                            //默认Text.QtRendering看起来比较模糊
                            renderType: Text.NativeRendering
                            background: Rectangle {
                                color: "#fdfbfb"
                            }

                            //信号
                            //长按时会发出此信号（延迟取决于平台插件）
                            onPressAndHold: { /*event*/ }
                            //当用户按下文本字段时，将发出此信号
                            onPressed: {
                                console.log(textfield_2.width)
                            }
                            //当用户释放文本字段时，将发出此信号
                            onReleased: { /*event*/ }
                        }
                    }
                }
            }
        }
    }
}
