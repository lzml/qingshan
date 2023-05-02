import QtQuick
import QtQuick.Window
import QtQuick.Controls
import DlgMain

Window {
    id : wnd
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


       Column{
           x: 10
           y: 10
           spacing: 10

           CheckBox {
               id:ck_video
               text: qsTr("隐藏视频")
               checked: false


           }
           CheckBox {
               id:ck_picture
               text:qsTr("隐藏图片")
               checked: wndHandler.checkPic;
               Component.onCompleted:{
                   if(wndHandler.checkPic === 2){
                       ck_picture.enabled = false;
                   }
                   else {
                       ck_picture.enabled = true;
                       ck_picture.checked = wndHandler.checkPic;
                   }
               }

               //这里值相等就好
               onCheckStateChanged: function() {
                   if(wndHandler.checkPic != checked)
                   {
                       wndHandler.checkPic = checked;
                   }
               }
           }
       }
    }


    Component.onCompleted: {



    }


    DLgMain{
        id: wndHandler
    }

}
