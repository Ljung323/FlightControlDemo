#include "sources/Flight/Domain/ChangeAltitudeUsecase.h"

ChangeAltitudeUsecase::ChangeAltitudeUsecase(ChangeAltitudeDriver* changeAltitudeDriver) {
    this->changeAltitudeDriver = changeAltitudeDriver;
}

bool ChangeAltitudeUsecase::changeAltitude(int targetAltitude)
{
    return this->changeAltitudeDriver->changeAltitude(targetAltitude);
}
