#pragma once
#include <QObject>
#include <QTest>

class FlightPresenterTest: public QObject
{
    Q_OBJECT
private slots:
    void toAircraftInfoValueForDisplayTest();
};
