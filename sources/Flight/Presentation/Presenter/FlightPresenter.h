#pragma once
#include <QObject>
#include <QJSValue>
#include "sources/Flight/Framework/AircraftInfoDriver.h"
#include "sources/Flight/Framework/TakeoffDriver.h"
#include "sources/Flight/Framework/ChangeAltitudeDriver.h"
#include "sources/Flight/Framework/LandDriver.h"

class FlightPresenter: public QObject
{
    Q_OBJECT

private:
    AircraftInfoDriver* aircraftInfoDriver;
    TakeoffDriver* takeoffDriver;
    ChangeAltitudeDriver* changeAltitudeDriver;
    LandDriver* landDriver;

    void runCallback(QJSValue callback, bool result);

public:
    FlightPresenter(
            AircraftInfoDriver* aircraftInfoDriver,
            TakeoffDriver* takeoffDriver,
            ChangeAltitudeDriver* changeAltitudeDriver,
            LandDriver* landDriver
            );

    Q_INVOKABLE void startSubscribe();
    Q_INVOKABLE std::string toAircraftInfoValue(QJSValue title);
    Q_INVOKABLE void takeoff(QJSValue callback);
    Q_INVOKABLE void changeAltitude(QJSValue targetAltitude, QJSValue callback);
    Q_INVOKABLE void land(QJSValue callback);
};
