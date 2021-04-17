#pragma once
#include <QObject>
#include <QJSValue>
#include "sources/Flight/Framework/ConnectionDriver.h"

class HomePresenter: public QObject
{
    Q_OBJECT

private:
    ConnectionDriver* connectionDriver;

public:
    HomePresenter(ConnectionDriver* connectionDriver);

    Q_INVOKABLE void connect(QJSValue callback);
};
