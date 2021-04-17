#pragma once
#include "sources/Flight/Framework/ChangeAltitudeDriver.h"

class ChangeAltitudeUsecase
{
private:
    ChangeAltitudeDriver* changeAltitudeDriver;

public:
    ChangeAltitudeUsecase(ChangeAltitudeDriver* changeAltitudeDriver);

    bool changeAltitude(int targetAltitude);
};
