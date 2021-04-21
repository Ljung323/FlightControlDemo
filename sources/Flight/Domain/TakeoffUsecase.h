#pragma once
#include "sources/Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.h"

class TakeoffUsecase
{
private:
    TakeoffDriverProtocol* takeoffDriver;

public:
    TakeoffUsecase(TakeoffDriverProtocol* takeoffDriver);

    bool takeoff();
};
