#pragma once
#include <mavsdk/mavsdk.h>
#include "Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.h"
#include "Flight/Domain/Position.h"

using namespace mavsdk;

class ChangeAltitudeDriverForMAVSDK: public ChangeAltitudeDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    ChangeAltitudeDriverForMAVSDK(Mavsdk* mavsdk);

    bool changeAltitude(int targetAltitude, Position currentPosition) override;
};
