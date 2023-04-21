import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle{
       anchors.fill: parent
       color:"#f0f0f0"
       Text {
           text: "青山不改，绿水长流"
           anchors.centerIn: parent
       }
    }

    Column{
        anchors.top: parent.top + 10
        spacing: 10

        CheckBox {
            text: qsTr("隐藏视频")
            checked: false
        }
        CheckBox {
            text:qsTr("隐藏图片")
            checked:false
        }
    }


}
