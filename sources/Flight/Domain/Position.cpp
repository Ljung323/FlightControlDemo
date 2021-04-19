#include "sources/Flight/Domain/Position.h"

Position::Position(float latitude, float longitude, float relativeAltitude, float absoluteAltitude) {
    this->latitude = latitude;
    this->longitude = longitude;
    this->relativeAltitude = relativeAltitude;
    this->absoluteAltitude = absoluteAltitude;
}
