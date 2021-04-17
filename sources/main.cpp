#include <mavsdk/mavsdk.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "sources/Flight/Framework/ConnectionDriver.h"
#include "sources/Flight/Framework/TakeoffDriver.h"
#include "sources/Flight/Framework/LandDriver.h"
#include "sources/Flight/Presentation/Presenter/HomePresenter.h"
#include "sources/Flight/Presentation/Presenter/FlightPresenter.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    mavsdk::Mavsdk mavsdk;

    // drivers
    ConnectionDriver connectionDriver(&mavsdk);
    TakeoffDriver takeoffDriver(&mavsdk);
    LandDriver landDriver(&mavsdk);

    // presenters
    HomePresenter homePresenter(&connectionDriver);
    FlightPresenter flightPresenter(&takeoffDriver, &landDriver);
    engine.rootContext()->setContextProperty("HomePresenter", &homePresenter);
    engine.rootContext()->setContextProperty("FlightPresenter", &flightPresenter);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
