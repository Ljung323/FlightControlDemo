#pragma once
#include <QObject>
#include <QJSValue>
#include "sources/Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.h"

class HomePresenter: public QObject
{
    Q_OBJECT

private:
    ConnectionDriverProtocol* connectionDriver;

public:
    HomePresenter(ConnectionDriverProtocol* connectionDriver);

    Q_INVOKABLE void connect(QJSValue callback);
};
