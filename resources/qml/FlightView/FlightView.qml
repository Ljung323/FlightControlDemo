import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import FlightInfo 1.0

Page {
    id: flightView

    background: MapView {
        id: mapView

        latitude: 0
        longitude: 0

        MouseArea {
            id: mapMouseArea
            anchors.fill: parent

            onDoubleClicked: moveHorizontally(Qt.point(mapMouseArea.mouseX, mapMouseArea.mouseY))
        }
    }

    ToolView {
        id: toolView

        width: parent.width * 0.1
        height: parent.height * 0.3

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

    Timer {
        id: timer

        interval: 1
        repeat: true
        onTriggered: {
            updateAircraftInfo()
            updateCenterLocationOnMap()
        }
    }

    function onAppear() {
        FlightPresenter.startSubscribe()
        timer.start()
    }

    function moveHorizontally(position) {
        const coordinate = mapView.toCoordinate(position)
        FlightPresenter.moveHorizontally(
                    coordinate.latitude,
                    coordinate.longitude,
                    {}
                    )
    }

    function updateAircraftInfo() {
        infoView.aircraftBattery = FlightPresenter.toAircraftInfoValueForDisplay(FlightInfo.AircraftBattery)
        infoView.inAir = FlightPresenter.toAircraftInfoValueForDisplay(FlightInfo.InAir)
        infoView.altitude = FlightPresenter.toAircraftInfoValueForDisplay(FlightInfo.Altitude)
    }

    function updateCenterLocationOnMap() {
        mapView.latitude = FlightPresenter.toAircraftInfoValue("Latitude")
        mapView.longitude = FlightPresenter.toAircraftInfoValue("Longitude")
    }

    function takeoffTapped() {
        FlightPresenter.takeoff({})
    }

    function selectAltitudeTapped() {
        selectAltitudeView.show()
    }

    function landTapped() {
        FlightPresenter.land({})
    }
}
