import QtQuick 2.0
import QtQuick.Controls 2.12

Button {
    id: actionButton

    property string titleText: ""
    contentItem: Text {
        text: qsTr(titleText)
        color: actionButton.pressed ? "#aaaaaa" : "#ffffff"
        font {
            bold: true
            pointSize: 12
        }
    }

    background: Rectangle {
        width: 60
        height: width
        color: actionButton.pressed ? "#444444" : "#777777"
        radius: 5
        anchors.centerIn: parent
    }
}
