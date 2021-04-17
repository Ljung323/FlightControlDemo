#pragma once
#include <mavsdk/mavsdk.h>

using namespace mavsdk;

class ChangeAltitudeDriver
{
private:
    Mavsdk* mavsdk;

public:
    ChangeAltitudeDriver(Mavsdk* mavsdk);

    bool changeAltitude(int targetAltitude);
};
