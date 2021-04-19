#include "sources/Flight/Domain/AircraftInfoUsecase.h"

AircraftInfoUsecase::AircraftInfoUsecase(AircraftInfoDriver* aircraftInfoDriver) {
    this->aircraftInfoDriver = aircraftInfoDriver;
}

void AircraftInfoUsecase::startSubscribe()
{
    this->aircraftInfoDriver->startSubscribe();
}
