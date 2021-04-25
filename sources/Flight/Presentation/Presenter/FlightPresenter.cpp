#include <iostream>
#include <QJSValue>
#include <QJSEngine>
#include "sources/Flight/Presentation/Presenter/FlightPresenter.h"
#include "sources/Flight/Domain/Position.h"
#include "sources/Flight/Domain/TakeoffUsecase.h"
#include "sources/Flight/Domain/ChangeAltitudeUsecase.h"
#include "sources/Flight/Domain/HorizontalMoveUsecase.h"
#include "sources/Flight/Domain/LandUsecase.h"
#include "sources/Flight/Domain/FlightInfo.h"

#define STR(var) #var

using std::to_string;
using std::string;

FlightPresenter::FlightPresenter(
        AircraftInfoDriverProtocol* aircraftInfoDriver,
        TakeoffDriverProtocol* takeoffDriver,
        ChangeAltitudeDriverProtocol* changeAltitudeDriver,
        HorizontalMoveDriverProtocol* horizontalMoveDriver,
        LandDriverProtocol* landDriver
        ) {
    this->aircraftInfoDriver = aircraftInfoDriver;
    this->takeoffDriver = takeoffDriver;
    this->changeAltitudeDriver = changeAltitudeDriver;
    this->horizontalMoveDriver = horizontalMoveDriver;
    this->landDriver = landDriver;
}

void FlightPresenter::startSubscribe() {
    this->aircraftInfoDriver->startSubscribe();
}

QString FlightPresenter::toAircraftInfoValueForDisplay(QJSValue item) {
    int flightAction = item.toInt();
    switch (flightAction) {
    case FlightInfo::AircraftBattery:
        {
            string title = STR(AircraftBattery);
            string value = to_string(int(this->aircraftInfoDriver->aircraftBattery * 100)) + "%";
            value = title + ": " + value;
            return QString::fromStdString(value);
        }
    case FlightInfo::InAir:
        {
            string title = STR(InAir);
            // TODO: there should be a more simple way to just display true / false, not 0 / 1
            string value = this->aircraftInfoDriver->isInAir ? "yes" : "no";
            value = title + ": " + value;
            return QString::fromStdString(value);
        }
    case FlightInfo::Altitude:
        {
            string title = STR(Altitude);
            string value = to_string(int(this->aircraftInfoDriver->position.relativeAltitude)) + "m";
            value = title + ": " + value;
            return QString::fromStdString(value);
        }
    }
}

QJSValue FlightPresenter::toAircraftInfoValue(QJSValue title) {
    // TODO: consider to use enum
    QString stringTitle = title.toString();
    if (stringTitle == "Latitude") {
        return aircraftInfoDriver->position.latitude;
    } else if (stringTitle == "Longitude") {
        return aircraftInfoDriver->position.longitude;
    } else {
        return "invalid input";
    }
}

void FlightPresenter::runCallback(QJSValue callback, bool result) {
    QJSEngine *engine = callback.engine();
    QJSValue value = engine->newObject();
    value.setProperty("result", result);
    callback.call(QJSValueList { value });
}

void FlightPresenter::takeoff(QJSValue callback)
{
    TakeoffUsecase usecase(this->takeoffDriver);
    this->runCallback(callback, usecase.takeoff());
}

void FlightPresenter::changeAltitude(QJSValue targetAltitude, QJSValue callback) {
    ChangeAltitudeUsecase usecase(this->changeAltitudeDriver);
    this->runCallback(callback, usecase.changeAltitude(targetAltitude.toInt(), aircraftInfoDriver->position));
}

void FlightPresenter::moveHorizontally(QJSValue latitude, QJSValue longitude, QJSValue callback) {
    HorizontalMoveUsecase usecase(this->horizontalMoveDriver);
    this->runCallback(
                callback,
                usecase.moveHorizontally(Position(
                                             latitude.toNumber(),
                                             longitude.toNumber(),
                                             aircraftInfoDriver->position.relativeAltitude,
                                             aircraftInfoDriver->position.absoluteAltitude)
                                         )
                );
}

void FlightPresenter::land(QJSValue callback) {
    LandUsecase usecase(this->landDriver);
    this->runCallback(callback, usecase.land());
}
