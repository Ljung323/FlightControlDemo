#pragma once
#include "Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.h"
#include "Flight/Domain/Position.h"

class HorizontalMoveUsecase
{
private:
    HorizontalMoveDriverProtocol* horizontalMoveDriver;

public:
    HorizontalMoveUsecase(HorizontalMoveDriverProtocol* horizontalMoveDriver);

    bool moveHorizontally(Position position);
};
