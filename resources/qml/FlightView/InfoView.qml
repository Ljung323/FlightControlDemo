import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    property string aircraftBattery: "-"
    property string inAir: "-"
    property string altitude: "-"

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
                    text: toValue(model.title)
                    color: "#ffffff"
                }
            }
        }

        anchors {
            fill: rect
            margins: 20
        }
    }

    function toValue(title) {
        if (title === "AircraftBattery") {
            return aircraftBattery
        } else if (title === "InAir") {
            return inAir
        } else if (title === "Altitude") {
            return altitude
        } else {
            console.error("invalid input")
            return ""
        }
    }
}
