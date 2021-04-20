import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    ColumnLayout {
        spacing: 60

        Repeater {
            model: ActionListModel {}

            delegate: Button {
                id: button

                contentItem: Text {
                    text: qsTr(model.title)
                    color: button.pressed ? "#aaaaaa" : "#ffffff"
                    font {
                        bold: true
                        pointSize: 12
                    }
                }

                background: Rectangle {
                    width: 60
                    height: width
                    color: button.pressed ? "#444444" : "#777777"
                    radius: 5
                    anchors.centerIn: parent
                }

                Layout.alignment: Qt.AlignHCenter

                onClicked: flightView.buttonTapped(model.title)
            }
        }
    }
}
