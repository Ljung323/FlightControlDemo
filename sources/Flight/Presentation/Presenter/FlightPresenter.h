#pragma once
#include <QObject>
#include <QJSValue>
#include "sources/Flight/Framework/TakeoffDriver.h"
#include "sources/Flight/Framework/LandDriver.h"

class FlightPresenter: public QObject
{
    Q_OBJECT

private:
    TakeoffDriver* takeoffDriver;
    LandDriver* landDriver;

    void runCallback(QJSValue callback, bool result);
    void takeoff(QJSValue callback);
    void land(QJSValue callback);

public:
    FlightPresenter(TakeoffDriver* takeoffDriver, LandDriver* landDriver);

    Q_INVOKABLE void runAction(QJSValue action, QJSValue callback);
};
