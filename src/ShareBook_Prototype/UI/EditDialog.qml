import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
import QtQuick.Layouts
Page {
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
                console.log(textfield_title.text)
//                if(textarea_content.text===""&&素材也为空)------>提示用户必须选择一个输入
                //如果只有图片，自动添加标题“分享图片”
                if(textfield_title.text===""&&textarea_content.text==="")
                {
                    //textfield_title.text="分享图片"
                }
                //如果有内容但没有标题，标题为内容的前二十个字
                else{ if(textfield_title.text===""){
                    textfield_title.text=textarea_content.text.substring(0,20)
                }
                control.requestPublish(textfield_title.text,textarea_content.text,[]);
                stack.clear()}
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
        }
        Rectangle{
            id:edit
            width: background.width-20
            height:background.height-10
            radius: 20
            anchors.centerIn: parent
            color: "#fdfbfb"
            layer.enabled: true
            layer.effect: OpacityMask {
                maskSource: Rectangle {
                    width: edit.width
                    height: edit.height
                    radius: edit.radius
                }
            }

            TextField{
                id: textfield_title
                width: edit.width
                anchors.horizontalCenter: parent.horizontalCenter
                padding: 30
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
                maximumLength:20
                //默认Text.QtRendering看起来比较模糊
                renderType: Text.NativeRendering
                background: Rectangle {
                    color: "#fdfbfb"
                }
            }

            Rectangle{
                id:line
                width: edit.width
                height: 5
                anchors.top:textfield_title.bottom
                color: "#53B7AF"
            }
            //选择素材的按钮，有素材后按钮后移//
            Button{}
            //存放选择的素材，是横着的list

            ListView{

            }
            ScrollView{
                width: edit.width
                anchors.top: line.bottom
                anchors.bottom: edit.bottom
                TextArea{
                    id:textarea_content
                    topPadding: 30
                    leftPadding: 30
                    rightPadding: 30
                    //无输入时显示的文本
                    placeholderText: "输入文本内容（500个字）"
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
                    //maximumLength:500//超出可输入的文本有提示
                    wrapMode:TextEdit.Wrap
                    //默认Text.QtRendering看起来比较模糊
                    renderType: Text.NativeRendering
                    background: Rectangle {
                        color: "#fdfbfb"
                    }
                }
            }
        }
    }
}
