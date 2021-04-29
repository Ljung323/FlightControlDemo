#pragma once
#include <mavsdk/mavsdk.h>
#include "Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.h"
#include "Flight/Domain/Position.h"

using namespace mavsdk;

class HorizontalMoveDriverForMAVSDK: public HorizontalMoveDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    HorizontalMoveDriverForMAVSDK(Mavsdk* mavsdk);

    bool moveHorizontally(Position position) override;
};
