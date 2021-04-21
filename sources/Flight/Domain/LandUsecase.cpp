#include "sources/Flight/Domain/LandUsecase.h"

LandUsecase::LandUsecase(LandDriverProtocol* landDriver) {
    this->landDriver = landDriver;
}

bool LandUsecase::land()
{
    return this->landDriver->land();
}
