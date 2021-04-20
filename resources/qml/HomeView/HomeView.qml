import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import "../FlightView"

Page {
    id: homeView
    background: Rectangle {
        color: "#DEDEDE"
    }

    property var flightView: FlightView {}

    ColumnLayout {
        Image {
            source: "qrc:/uav.svg"
            sourceSize.width: 250
            sourceSize.height: 250
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            id: connectButton
            contentItem: Text {
                text: qsTr("Connect Aircraft")
                color: connectButton.pressed ? "#999999" : "#eeeeee"
                font {
                    bold: true
                    pointSize: 24
                }
            }

            background: Rectangle {
                width: parent.width + 20
                height: parent.height
                color: connectButton.pressed ? "#333333" : "#555555"
                radius: 5
                anchors.centerIn: parent
            }

            Layout.alignment: Qt.AlignHCenter

            onClicked: connectButtonTapped(function () {
                stackView.push(flightView)
                // TODO: find suitable life cycle within flightView
                flightView.onAppear()
            })
        }

        anchors.centerIn: parent
        anchors.verticalCenterOffset: -20
    }

    function connectButtonTapped(callback) {
        HomePresenter.connect(function (object) {
            if (object.result) {
                console.log("connect succeeded")
                callback()
            } else {
                console.error("connect failed")
            }
        })
    }
}
