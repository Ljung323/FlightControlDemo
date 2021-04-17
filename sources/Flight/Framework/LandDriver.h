#pragma once
#include <mavsdk/mavsdk.h>

using namespace mavsdk;

class LandDriver
{
private:
    Mavsdk* mavsdk;

public:
    LandDriver(Mavsdk* mavsdk);

    bool land();
};
