#pragma once

struct Position
{
public:
    float latitude;
    float longitude;
    float relativeAltitude;
    float absoluteAltitude;

    Position(float latitude, float longitude, float relativeAltitude, float absoluteAltitude);
};
