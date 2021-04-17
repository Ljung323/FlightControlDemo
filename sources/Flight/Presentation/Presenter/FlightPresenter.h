#pragma once
#include <QObject>
#include <QJSValue>
#include "sources/Flight/Framework/TakeoffDriver.h"

class FlightPresenter: public QObject
{
    Q_OBJECT

private:
    TakeoffDriver* takeoffDriver;

    void runCallback(QJSValue callback, bool result);
    void takeoff(QJSValue callback);

public:
    FlightPresenter(TakeoffDriver* takeoffDriver);

    Q_INVOKABLE void runAction(QJSValue action, QJSValue callback);
};
