import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    property var isVisible: false

    visible: isVisible

    Rectangle {
        id: selectAltitudeViewBackground
        color: "#DEDEDE"
        radius: 5
        anchors.fill: parent
    }

    ColumnLayout {
        Tumbler {
            id: selectAltitudeTumbler
            model: Array.from(Array(150)).map((v,k)=> k + 1)
            background: Rectangle {
                width: parent.height + 20
                height: parent.height + 20
                color: "#ffffff"
                radius: 5
                anchors.centerIn: parent
            }

            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            id: selectAltitudeButton
            contentItem: Text {
                text: qsTr("OK")
                color: "#eeeeee"
                font {
                    bold: true
                    pointSize: 16
                }
            }

            background: Rectangle {
                width: parent.width + 20
                height: parent.height
                color: "#555555"
                radius: 5
                anchors.centerIn: parent
            }

            Layout.alignment: Qt.AlignHCenter

            onClicked: selectAltitudeButtonTapped(selectAltitudeTumbler.currentIndex + 1)
        }

        anchors {
            fill: selectAltitudeViewBackground
            margins: 20
        }
    }

    function show() {
        isVisible = true
    }

    function hide() {
        isVisible = false
    }

    function selectAltitudeButtonTapped(targetAltitude) {
        FlightPresenter.changeAltitude(targetAltitude, hide())
    }
}
