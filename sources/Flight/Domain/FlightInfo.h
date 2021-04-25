#pragma once
#include <QObject>

class FlightInfo: public QObject {
    Q_OBJECT
    Q_ENUMS(Value)

public:
    enum Value {
        AircraftBattery,
        InAir,
        Altitude
    };
};
