import QtQuick 2.12
import QtQuick.Controls 2.12

import "FlightView"
import "HomeView"

ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: HomeView {}
    }
}
