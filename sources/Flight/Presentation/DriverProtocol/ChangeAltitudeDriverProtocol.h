#pragma once
#include "sources/Flight/Domain/Position.h"

class ChangeAltitudeDriverProtocol{
public:
    virtual ~ChangeAltitudeDriverProtocol() = 0;

    virtual bool changeAltitude(int targetAltitude, Position currentPosition) = 0;
};
