#pragma once
#include "sources/Flight/Framework/TakeoffDriver.h"

class TakeoffUsecase
{
private:
    TakeoffDriver* takeoffDriver;

public:
    TakeoffUsecase(TakeoffDriver* takeoffDriver);

    bool takeoff();
};
