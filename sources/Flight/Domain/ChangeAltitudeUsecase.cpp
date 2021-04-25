#include "sources/Flight/Domain/ChangeAltitudeUsecase.h"

ChangeAltitudeUsecase::ChangeAltitudeUsecase(ChangeAltitudeDriverProtocol* changeAltitudeDriver) {
    this->changeAltitudeDriver = changeAltitudeDriver;
}

bool ChangeAltitudeUsecase::changeAltitude(int targetAltitude, Position currentPosition)
{
    return this->changeAltitudeDriver->changeAltitude(targetAltitude, currentPosition);
}
