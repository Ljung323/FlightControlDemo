import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12

Page {
    id: flightView
    background: Rectangle { color: "#ffffff" }

    ToolView {
        id: toolView

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
        id: infoView

        width: parent.width * 0.4
        height: parent.height * 0.3

        anchors {
            top: parent.top
            topMargin: parent.height * 0.05
            right: parent.right
            rightMargin: parent.width * 0.05
        }
    }    

    SelectAltitudeView {
        id: selectAltitudeView

        anchors {
            left: parent.left
            leftMargin: parent.width * 0.2
            top: parent.top
            topMargin: parent.height * 0.1
            right: parent.right
            rightMargin: parent.width * 0.2
            bottom: parent.bottom
            bottomMargin: parent.height * 0.1
        }
    }

    function onAppear() {
        FlightPresenter.startSubscribe()
    }

    function buttonTapped(actionTitle) {
        if (actionTitle === "Takeoff") {
            FlightPresenter.takeoff({})
        } else if (actionTitle === "Altitude") {
            selectAltitudeView.show()
        } else if (actionTitle === "Land") {
            FlightPresenter.land({})
        } else {
            console.error("invalid action")
        }
    }
}
