#include "FlightPresenterTest.h"
#include "../../sources/Flight/Presentation/Presenter/FlightPresenter.h"
#include "../../sources/Flight/Presentation/DriverProtocol/AircraftInfoDriverProtocol.h"
#include "../../sources/Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.h"
#include "../../sources/Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.h"
#include "../../sources/Flight/Presentation/DriverProtocol/LandDriverProtocol.h"
#include "../../sources/Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.h"
#include "../../sources/Flight/Domain/FlightInfo.h"
#include "../../sources/Flight/Domain/Position.h"

// mock drivers
class MockAircraftInfoDriver: public AircraftInfoDriverProtocol {
    void startSubscribe() {}
};
AircraftInfoDriverProtocol::~AircraftInfoDriverProtocol() {}

class MockChangeAltitudeDriver: public ChangeAltitudeDriverProtocol {
    bool changeAltitude(int targetAltitude, Position currentPosition) { return true; }
};
ChangeAltitudeDriverProtocol::~ChangeAltitudeDriverProtocol() {}

class MockHorizontalMoveDriver: public HorizontalMoveDriverProtocol {
    bool moveHorizontally(Position position) { return true; }
};
HorizontalMoveDriverProtocol::~HorizontalMoveDriverProtocol() {}

class MockLandDriver: public LandDriverProtocol {
    bool land() { return true; }
};
LandDriverProtocol::~LandDriverProtocol() {}

class MockTakeoffDriver : public TakeoffDriverProtocol {
    bool takeoff() { return true; }
};
TakeoffDriverProtocol::~TakeoffDriverProtocol() {}

void FlightPresenterTest::toAircraftInfoValueForDisplayTest() {
    MockAircraftInfoDriver mockAircraftInfoDriver;
    MockChangeAltitudeDriver mockChangeAltitudeDriver;
    MockHorizontalMoveDriver mockHorizontalMoveDriver;
    MockLandDriver mockLandDriver;
    MockTakeoffDriver mockTakeoffDriver;
    FlightPresenter presenter(&mockAircraftInfoDriver, &mockTakeoffDriver, &mockChangeAltitudeDriver, &mockHorizontalMoveDriver, &mockLandDriver);

    QString str;

    // aircraft battery
    mockAircraftInfoDriver.aircraftBattery = 0;
    str = presenter.toAircraftInfoValueForDisplay(QJSValue(FlightInfo::AircraftBattery));
    QCOMPARE(str, QString("AircraftBattery: 0%"));

    mockAircraftInfoDriver.aircraftBattery = 1;
    str = presenter.toAircraftInfoValueForDisplay(QJSValue(FlightInfo::AircraftBattery));
    QCOMPARE(str, QString("AircraftBattery: 100%"));

    // in air
    mockAircraftInfoDriver.isInAir = false;
    str = presenter.toAircraftInfoValueForDisplay(QJSValue(FlightInfo::InAir));
    QCOMPARE(str, QString("InAir: no"));

    mockAircraftInfoDriver.isInAir = true;
    str = presenter.toAircraftInfoValueForDisplay(QJSValue(FlightInfo::InAir));
    QCOMPARE(str, QString("InAir: yes"));

    // altitude
    mockAircraftInfoDriver.position = Position(0, 0, 0, 0);
    str = presenter.toAircraftInfoValueForDisplay(QJSValue(FlightInfo::Altitude));
    QCOMPARE(str, QString("Altitude: 0m"));

    mockAircraftInfoDriver.position = Position(0, 0, 100, 0);
    str = presenter.toAircraftInfoValueForDisplay(QJSValue(FlightInfo::Altitude));
    QCOMPARE(str, QString("Altitude: 100m"));
}

QTEST_APPLESS_MAIN(FlightPresenterTest)
