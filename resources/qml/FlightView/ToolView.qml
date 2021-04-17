import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    id: toolView

    ColumnLayout {
        spacing: 60

        Repeater {
            model: ActionListModel {}

            delegate: Button {
                contentItem: Text {
                    text: qsTr(model.title)
                    color: "#ffffff"
                    font {
                        bold: true
                        pointSize: 12
                    }
                }

                background: Rectangle {
                    width: 60
                    height: width
                    color: "#777777"
                    radius: 5
                    anchors.centerIn: parent
                }

                Layout.alignment: Qt.AlignHCenter

                onClicked: buttonTapped(model.title)
            }
        }
    }

    function buttonTapped(actionTitle) {
        FlightPresenter.runAction(actionTitle, {})
    }
}
