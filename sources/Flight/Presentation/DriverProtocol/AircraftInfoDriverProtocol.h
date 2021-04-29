#pragma once
#include <thread>
#include "Flight/Domain/Position.h"

class AircraftInfoDriverProtocol {
public:
    Position position = Position(-1, -1, -1, -1);
    float aircraftBattery = -1;
    bool isInAir = false;

    virtual ~AircraftInfoDriverProtocol() = 0;

    virtual void startSubscribe() = 0;
};

