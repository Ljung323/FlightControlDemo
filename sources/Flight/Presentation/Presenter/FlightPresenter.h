#pragma once
#include <QObject>
#include <QJSValue>
#include "sources/Flight/Presentation/DriverProtocol/AircraftInfoDriverProtocol.h"
#include "sources/Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.h"
#include "sources/Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.h"
#include "sources/Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.h"
#include "sources/Flight/Presentation/DriverProtocol/LandDriverProtocol.h"

class FlightPresenter: public QObject
{
    Q_OBJECT

private:
    AircraftInfoDriverProtocol* aircraftInfoDriver;
    TakeoffDriverProtocol* takeoffDriver;
    ChangeAltitudeDriverProtocol* changeAltitudeDriver;
    HorizontalMoveDriverProtocol* horizontalMoveDriver;
    LandDriverProtocol* landDriver;

    void runCallback(QJSValue callback, bool result);

public:
    FlightPresenter(
            AircraftInfoDriverProtocol* aircraftInfoDriver,
            TakeoffDriverProtocol* takeoffDriver,
            ChangeAltitudeDriverProtocol* changeAltitudeDriver,
            HorizontalMoveDriverProtocol* horizontalMoveDriver,
            LandDriverProtocol* landDriver
            );

    Q_INVOKABLE void startSubscribe();
    Q_INVOKABLE QString toAircraftInfoValueForDisplay(QJSValue title);
    Q_INVOKABLE QJSValue toAircraftInfoValue(QJSValue title);
    Q_INVOKABLE void takeoff(QJSValue callback);
    Q_INVOKABLE void changeAltitude(QJSValue targetAltitude, QJSValue callback);
    Q_INVOKABLE void moveHorizontally(QJSValue latitude, QJSValue longitude, QJSValue callback);
    Q_INVOKABLE void land(QJSValue callback);
};
