#pragma once
#include <QObject>
#include <QJSValue>
#include "Flight/Presentation/DriverProtocol/AircraftInfoDriverProtocol.h"
#include "Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.h"
#include "Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.h"
#include "Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.h"
#include "Flight/Presentation/DriverProtocol/LandDriverProtocol.h"

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
    Q_INVOKABLE QString toAircraftInfoValueForDisplay(QJSValue item);
    Q_INVOKABLE QJSValue toAircraftInfoValue(QJSValue title);
    Q_INVOKABLE void takeoff(QJSValue callback);
    Q_INVOKABLE void changeAltitude(QJSValue targetAltitude, QJSValue callback);
    Q_INVOKABLE void moveHorizontally(QJSValue latitude, QJSValue longitude, QJSValue callback);
    Q_INVOKABLE void land(QJSValue callback);
};
