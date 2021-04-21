#pragma once
#include "sources/Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.h"

class ChangeAltitudeUsecase
{
private:
    ChangeAltitudeDriverProtocol* changeAltitudeDriver;

public:
    ChangeAltitudeUsecase(ChangeAltitudeDriverProtocol* changeAltitudeDriver);

    bool changeAltitude(int targetAltitude);
};
