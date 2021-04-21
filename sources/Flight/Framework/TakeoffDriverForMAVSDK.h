#pragma once
#include <mavsdk/mavsdk.h>
#include "sources/Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.h"

using namespace mavsdk;

class TakeoffDriverForMAVSDK: public TakeoffDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    TakeoffDriverForMAVSDK(Mavsdk* mavsdk);

    bool takeoff() override;
};
