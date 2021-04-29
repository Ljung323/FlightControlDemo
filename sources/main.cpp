#include <mavsdk/mavsdk.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Flight/Framework/ConnectionDriverForMAVSDK.h"
#include "Flight/Framework/AircraftInfoDriverForMAVSDK.h"
#include "Flight/Framework/TakeoffDriverForMAVSDK.h"
#include "Flight/Framework/ChangeAltitudeDriverForMAVSDK.h"
#include "Flight/Framework/HorizontalMoveDriverForMAVSDK.h"
#include "Flight/Framework/LandDriverForMAVSDK.h"
#include "Flight/Presentation/Presenter/HomePresenter.h"
#include "Flight/Presentation/Presenter/FlightPresenter.h"
#include "Flight/Domain/FlightAction.h"
#include "Flight/Domain/FlightInfo.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    mavsdk::Mavsdk mavsdk;

    // drivers for MAVSDK
    // they can be changed to other types of drivers (ex. driver For MAVLINK)
    ConnectionDriverForMAVSDK connectionDriver(&mavsdk);
    AircraftInfoDriverForMAVSDK aircraftInfoDriver(&mavsdk);
    ChangeAltitudeDriverForMAVSDK changeAltitudeDriver(&mavsdk);
    HorizontalMoveDriverForMAVSDK horizontalMoveDriver(&mavsdk);
    TakeoffDriverForMAVSDK takeoffDriver(&mavsdk);
    LandDriverForMAVSDK landDriver(&mavsdk);

    // presenters
    HomePresenter homePresenter(&connectionDriver);
    FlightPresenter flightPresenter(&aircraftInfoDriver, &takeoffDriver, &changeAltitudeDriver, &horizontalMoveDriver, &landDriver);
    engine.rootContext()->setContextProperty("HomePresenter", &homePresenter);
    engine.rootContext()->setContextProperty("FlightPresenter", &flightPresenter);

    // enum for list model
    qmlRegisterUncreatableType<FlightAction>("FlightAction", 1, 0, "FlightAction", "Not creatable as it is an enum type");
    qmlRegisterUncreatableType<FlightInfo>("FlightInfo", 1, 0, "FlightInfo", "Not creatable as it is an enum type");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
