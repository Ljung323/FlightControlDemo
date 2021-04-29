#pragma once
#include "Flight/Presentation/DriverProtocol/LandDriverProtocol.h"

class LandUsecase
{
private:
    LandDriverProtocol* landDriver;

public:
    LandUsecase(LandDriverProtocol* landDriver);

    bool land();
};
