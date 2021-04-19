#pragma once
#include <mavsdk/mavsdk.h>
#include "sources/Flight/Domain/Position.h"

using namespace mavsdk;

class HorizontalMoveDriver
{
private:
    Mavsdk* mavsdk;

public:
    HorizontalMoveDriver(Mavsdk* mavsdk);

    bool moveHorizontally(Position position);
};
