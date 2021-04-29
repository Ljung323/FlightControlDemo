#include "Flight/Domain/TakeoffUsecase.h"

TakeoffUsecase::TakeoffUsecase(TakeoffDriverProtocol* takeoffDriver) {
    this->takeoffDriver = takeoffDriver;
}

bool TakeoffUsecase::takeoff()
{
    return this->takeoffDriver->takeoff();
}
