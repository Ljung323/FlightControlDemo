#include <iostream>
#include <QJSValue>
#include <QJSEngine>
#include "sources/Flight/Presentation/Presenter/HomePresenter.h"
#include "sources/Flight/Domain/ConnectionUsecase.h"

HomePresenter::HomePresenter(ConnectionDriver* connectionDriver) {
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
