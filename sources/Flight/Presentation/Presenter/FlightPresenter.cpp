#include <iostream>
#include <QJSValue>
#include <QJSEngine>
#include "sources/Flight/Presentation/Presenter/FlightPresenter.h"
#include "sources/Flight/Domain/TakeoffUsecase.h"
#include "sources/Flight/Domain/LandUsecase.h"

FlightPresenter::FlightPresenter(TakeoffDriver* takeoffDriver, LandDriver* landDriver) {
    this->takeoffDriver = takeoffDriver;
    this->landDriver = landDriver;
}

void FlightPresenter::runAction(QJSValue action, QJSValue callback) {
    QString actionTitle = action.toString();
    if (actionTitle == "Takeoff") {
        this->takeoff(callback);
    } else if (actionTitle == "Land") {
        this->land(callback);
    } else {
        std::cout << "invalid action" << std::endl;
        this->runCallback(callback, false);
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

void FlightPresenter::land(QJSValue callback) {
    LandUsecase usecase(this->landDriver);
    this->runCallback(callback, usecase.land());
}
