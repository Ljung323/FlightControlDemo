#pragma once
#include <mavsdk/mavsdk.h>
#include "sources/Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.h"
#include "sources/Flight/Domain/Position.h"

using namespace mavsdk;

class HorizontalMoveDriver: public HorizontalMoveDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    HorizontalMoveDriver(Mavsdk* mavsdk);

    bool moveHorizontally(Position position) override;
};
