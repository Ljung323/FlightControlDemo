#include "sources/Flight/Domain/TakeoffUsecase.h"

TakeoffUsecase::TakeoffUsecase(TakeoffDriver* takeoffDriver) {
    this->takeoffDriver = takeoffDriver;
}

bool TakeoffUsecase::takeoff()
{
    return this->takeoffDriver->takeoff();
}
