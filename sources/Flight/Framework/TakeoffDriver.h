#pragma once
#include <mavsdk/mavsdk.h>

using namespace mavsdk;

class TakeoffDriver
{
private:
    Mavsdk* mavsdk;

public:
    TakeoffDriver(Mavsdk* mavsdk);

    bool takeoff();
};
