#pragma once
#include <mavsdk/mavsdk.h>
#include "sources/Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.h"

using namespace mavsdk;

class TakeoffDriver: public TakeoffDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    TakeoffDriver(Mavsdk* mavsdk);

    bool takeoff() override;
};
