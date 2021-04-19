#pragma once
#include "sources/Flight/Framework/AircraftInfoDriver.h"
#include "sources/Flight/Domain/Position.h"

class AircraftInfoUsecase
{
private:
    AircraftInfoDriver* aircraftInfoDriver;

public:
    Position position = Position(-1, -1, -1);
    float aircraftBattery = -1;
    bool isInAir = false;

    AircraftInfoUsecase(AircraftInfoDriver* aircraftInfoDriver);

    void startSubscribe();
};
