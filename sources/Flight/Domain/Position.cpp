#include "sources/Flight/Domain/Position.h"

Position::Position(float latitude, float longitude, float relativeAltitude) {
    this->latitude = latitude;
    this->longitude = longitude;
    this->relativeAltitude = relativeAltitude;
}
