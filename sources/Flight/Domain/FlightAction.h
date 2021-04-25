#pragma once
#include <QObject>

class FlightAction: public QObject {
    Q_OBJECT
    Q_ENUMS(Value)

public:
    enum Value {
        Takeoff,
        Altitude,
        Land
    };
};
