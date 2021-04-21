#pragma once
#include <mavsdk/mavsdk.h>
#include "sources/Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.h"

using namespace mavsdk;

class ChangeAltitudeDriver: public ChangeAltitudeDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    ChangeAltitudeDriver(Mavsdk* mavsdk);

    bool changeAltitude(int targetAltitude) override;
};
