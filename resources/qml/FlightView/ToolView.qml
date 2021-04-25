import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    ColumnLayout {
        spacing: 60

        ActionButton {
            titleText: "Takeoff"
            Layout.alignment: Qt.AlignHCenter
            onClicked: flightView.takeoffTapped()
        }

        ActionButton {
            titleText: "Altitude"
            Layout.alignment: Qt.AlignHCenter
            onClicked: flightView.selectAltitudeTapped()
        }

        ActionButton {
            titleText: "Land"
            Layout.alignment: Qt.AlignHCenter
            onClicked: flightView.landTapped()
        }
    }
}
