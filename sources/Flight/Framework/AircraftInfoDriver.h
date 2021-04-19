#pragma once
#include <mavsdk/mavsdk.h>
#include <thread>
#include "sources/Flight/Domain/Position.h"

using namespace mavsdk;

class AircraftInfoDriver
{
private:
    Mavsdk* mavsdk;
    std::thread subscribeThread;

    void subscribe();

public:
    Position position = Position(-1, -1, -1, -1);
    float aircraftBattery = -1;
    bool isInAir = false;

    AircraftInfoDriver(Mavsdk* mavsdk);
    ~AircraftInfoDriver();

    void startSubscribe();
};
