#include <iostream>
#include <QJSValue>
#include <QJSEngine>
#include "sources/Flight/Presentation/Presenter/FlightPresenter.h"
#include "sources/Flight/Domain/Position.h"
#include "sources/Flight/Domain/AircraftInfoUsecase.h"
#include "sources/Flight/Domain/TakeoffUsecase.h"
#include "sources/Flight/Domain/ChangeAltitudeUsecase.h"
#include "sources/Flight/Domain/HorizontalMoveUsecase.h"
#include "sources/Flight/Domain/LandUsecase.h"

FlightPresenter::FlightPresenter(
        AircraftInfoDriver* aircraftInfoDriver,
        TakeoffDriver* takeoffDriver,
        ChangeAltitudeDriver* changeAltitudeDriver,
        HorizontalMoveDriver* horizontalMoveDriver,
        LandDriver* landDriver
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

QString FlightPresenter::toAircraftInfoValue(QJSValue title) {
    QString stringTitle = title.toString();
    if (stringTitle == "AircraftBattery") {
        return QString::fromStdString(std::to_string(aircraftInfoDriver->aircraftBattery));
    } else if (stringTitle == "InAir") {
        return QString::fromStdString(aircraftInfoDriver->isInAir ? "yes" : "no"); // there should be a more simple way to just display true / false, not 0 / 1
    } else if (stringTitle == "Altitude") {
        return QString::fromStdString(std::to_string(aircraftInfoDriver->position.relativeAltitude));
    } else if (stringTitle == "AbsoluteAltitude") {
        return QString::fromStdString(std::to_string(aircraftInfoDriver->position.absoluteAltitude));
    } else if (stringTitle == "Latitude") {
        return QString::fromStdString(std::to_string(aircraftInfoDriver->position.latitude));
    } else if (stringTitle == "Longitude") {
        return QString::fromStdString(std::to_string(aircraftInfoDriver->position.longitude));
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

void FlightPresenter::moveHorizontally(QJSValue latitude, QJSValue longitude, QJSValue relativeAltitude, QJSValue absoluteAltitude, QJSValue callback) {
    HorizontalMoveUsecase usecase(this->horizontalMoveDriver);
    this->runCallback(
                callback,
                usecase.moveHorizontally(Position(latitude.toNumber(), longitude.toNumber(), relativeAltitude.toNumber(), absoluteAltitude.toNumber()))
                );
}

void FlightPresenter::land(QJSValue callback) {
    LandUsecase usecase(this->landDriver);
    this->runCallback(callback, usecase.land());
}
