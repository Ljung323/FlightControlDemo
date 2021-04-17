#include <iostream>
#include <QJSValue>
#include <QJSEngine>
#include "sources/Flight/Presentation/Presenter/FlightPresenter.h"
#include "sources/Flight/Domain/TakeoffUsecase.h"

FlightPresenter::FlightPresenter(TakeoffDriver* takeoffDriver) {
    this->takeoffDriver = takeoffDriver;
}

void FlightPresenter::runAction(QJSValue action, QJSValue callback) {
    if (action.toString() == "Takeoff") {
        this->takeoff(callback);
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
    TakeoffUsecase takeoffUsecase(this->takeoffDriver);
    this->runCallback(callback, takeoffUsecase.takeoff());
}
