#pragma once

class ChangeAltitudeDriverProtocol{
public:
    virtual ~ChangeAltitudeDriverProtocol() = 0;

    virtual bool changeAltitude(int targetAltitude) = 0;
};
