import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12

Page {
    id: flightView
    background: Rectangle { color: "#ffffff" }

    ToolView {
        width: parent.width * 0.1
        height: parent.height* 0.3

        anchors {
            top: parent.top
            topMargin: parent.height * 0.1
            left: parent.left
            leftMargin: parent.width * 0.05
        }
    }

    InfoView {
        width: parent.width * 0.4
        height: parent.height * 0.3

        anchors {
            top: parent.top
            topMargin: parent.height * 0.05
            right: parent.right
            rightMargin: parent.width * 0.05
        }
    }
}
