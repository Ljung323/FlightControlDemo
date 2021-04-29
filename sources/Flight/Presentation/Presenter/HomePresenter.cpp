#include <iostream>
#include <QJSValue>
#include <QJSEngine>
#include "Flight/Presentation/Presenter/HomePresenter.h"
#include "Flight/Domain/ConnectionUsecase.h"

HomePresenter::HomePresenter(ConnectionDriverProtocol* connectionDriver) {
    this->connectionDriver = connectionDriver;
}

void HomePresenter::connect(QJSValue callback)
{
    ConnectionUsecase connectionUsecase(this->connectionDriver);
    bool result = connectionUsecase.connect();
    QJSEngine *engine = callback.engine();
    QJSValue value = engine->newObject();
    value.setProperty("result", result);
    callback.call(QJSValueList { value });
}
