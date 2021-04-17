#include <iostream>
#include <QJSValue>
#include <QJSEngine>
#include "sources/Flight/Presentation/Presenter/FlightPresenter.h"
#include "sources/Flight/Domain/TakeoffUsecase.h"
#include "sources/Flight/Domain/ChangeAltitudeUsecase.h"
#include "sources/Flight/Domain/LandUsecase.h"

FlightPresenter::FlightPresenter(TakeoffDriver* takeoffDriver, ChangeAltitudeDriver* changeAltitudeDriver, LandDriver* landDriver) {
    this->takeoffDriver = takeoffDriver;
    this->changeAltitudeDriver = changeAltitudeDriver;
    this->landDriver = landDriver;
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
