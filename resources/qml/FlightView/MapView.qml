import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6

Item {
    property double latitude
    property double longitude

    Plugin {
        id: mapboxglPlugin
        name: "mapboxgl"
    }

    Map {
        id: map

        anchors.fill: parent
        plugin: mapboxglPlugin
        center: QtPositioning.coordinate(latitude, longitude)
        zoomLevel: 20
    }

    Text {
        text: "＋"
        font.pointSize: 30
        anchors.centerIn: parent
    }

    function toCoordinate(position) {
        return map.toCoordinate(position, false)
    }
}
