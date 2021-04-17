#include <mavsdk/mavsdk.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "sources/Flight/Framework/ConnectionDriver.h"
#include "sources/Flight/Presentation/Presenter/HomePresenter.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    mavsdk::Mavsdk mavsdk;

    // drivers
    ConnectionDriver connectionDriver(&mavsdk);

    // presenters
    HomePresenter homePresenter(&connectionDriver);
    engine.rootContext()->setContextProperty("HomePresenter", &homePresenter);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
