#pragma once

struct Position
{
public:
    float latitude;
    float longitude;
    float relativeAltitude;

    Position(float latitude, float longitude, float relativeAltitude);
};
