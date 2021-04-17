#pragma once
#include <QObject>
#include <QJSValue>
#include "sources/Flight/Framework/TakeoffDriver.h"
#include "sources/Flight/Framework/ChangeAltitudeDriver.h"
#include "sources/Flight/Framework/LandDriver.h"

class FlightPresenter: public QObject
{
    Q_OBJECT

private:
    TakeoffDriver* takeoffDriver;
    ChangeAltitudeDriver* changeAltitudeDriver;
    LandDriver* landDriver;

    void runCallback(QJSValue callback, bool result);

public:
    FlightPresenter(TakeoffDriver* takeoffDriver, ChangeAltitudeDriver* changeAltitudeDriver, LandDriver* landDriver);

    Q_INVOKABLE void takeoff(QJSValue callback);
    Q_INVOKABLE void changeAltitude(QJSValue targetAltitude, QJSValue callback);
    Q_INVOKABLE void land(QJSValue callback);
};
