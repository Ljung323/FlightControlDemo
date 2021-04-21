#pragma once
#include "sources/Flight/Presentation/DriverProtocol/LandDriverProtocol.h"

class LandUsecase
{
private:
    LandDriverProtocol* landDriver;

public:
    LandUsecase(LandDriverProtocol* landDriver);

    bool land();
};
