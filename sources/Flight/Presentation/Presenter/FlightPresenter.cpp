#include <iostream>
#include <QJSValue>
#include <QJSEngine>
#include "sources/Flight/Presentation/Presenter/FlightPresenter.h"
#include "sources/Flight/Domain/AircraftInfoUsecase.h"
#include "sources/Flight/Domain/TakeoffUsecase.h"
#include "sources/Flight/Domain/ChangeAltitudeUsecase.h"
#include "sources/Flight/Domain/LandUsecase.h"

FlightPresenter::FlightPresenter(AircraftInfoDriver* aircraftInfoDriver, TakeoffDriver* takeoffDriver, ChangeAltitudeDriver* changeAltitudeDriver, LandDriver* landDriver) {
    this->aircraftInfoDriver = aircraftInfoDriver;
    this->takeoffDriver = takeoffDriver;
    this->changeAltitudeDriver = changeAltitudeDriver;
    this->landDriver = landDriver;
}

void FlightPresenter::startSubscribe() {
    this->aircraftInfoDriver->startSubscribe();
}

std::string FlightPresenter::toAircraftInfoValue(QJSValue title) {
    QString stringTitle = title.toString();
    if (stringTitle == "AircraftBattery") {
        return std::to_string(aircraftInfoDriver->aircraftBattery);
    } else if (stringTitle == "InAir") {
        return std::to_string(aircraftInfoDriver->isInAir);
    } else if (stringTitle == "Altitude") {
        return std::to_string(aircraftInfoDriver->position.relativeAltitude);
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
    this->runCallback(callback, usecase.changeAltitude(targetAltitude.toInt()));
}

void FlightPresenter::land(QJSValue callback) {
    LandUsecase usecase(this->landDriver);
    this->runCallback(callback, usecase.land());
}
