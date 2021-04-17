#pragma once
#include "sources/Flight/Framework/LandDriver.h"

class LandUsecase
{
private:
    LandDriver* landDriver;

public:
    LandUsecase(LandDriver* landDriver);

    bool land();
};
