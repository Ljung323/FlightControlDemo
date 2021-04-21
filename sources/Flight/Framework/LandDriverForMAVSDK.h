#pragma once
#include <mavsdk/mavsdk.h>
#include "sources/Flight/Presentation/DriverProtocol/LandDriverProtocol.h"

using namespace mavsdk;

class LandDriverForMAVSDK: public LandDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    LandDriverForMAVSDK(Mavsdk* mavsdk);

    bool land() override;
};
