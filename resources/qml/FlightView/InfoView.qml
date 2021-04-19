import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    property string aircraftBattery: "-"

    Rectangle {
        id: rect
        color: "#777777"
        radius: 5
        anchors.fill: parent
    }

    ColumnLayout {

        Repeater {
            model: InfoListModel {}

            delegate: RowLayout {
                spacing: 5

                Text {
                    text: qsTr(model.title)
                    color: "#ffffff"
                }
                Text {
                    text: qsTr(FlightPresenter.toAircraftInfoValue(model.title))
                    color: "#ffffff"
                }
            }
        }

        anchors {
            fill: rect
            margins: 20
        }
    }
}
