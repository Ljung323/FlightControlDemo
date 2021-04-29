#pragma once
#include "Flight/Domain/Position.h"

class ChangeAltitudeDriverProtocol{
public:
    virtual ~ChangeAltitudeDriverProtocol() = 0;

    virtual bool changeAltitude(int targetAltitude, Position currentPosition) = 0;
};
