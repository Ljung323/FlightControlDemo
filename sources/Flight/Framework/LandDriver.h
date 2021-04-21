#pragma once
#include <mavsdk/mavsdk.h>
#include "sources/Flight/Presentation/DriverProtocol/LandDriverProtocol.h"

using namespace mavsdk;

class LandDriver: public LandDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    LandDriver(Mavsdk* mavsdk);

    bool land() override;
};
