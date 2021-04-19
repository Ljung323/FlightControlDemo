#pragma once
#include "sources/Flight/Framework/HorizontalMoveDriver.h"
#include "sources/Flight/Domain/Position.h"

class HorizontalMoveUsecase
{
private:
    HorizontalMoveDriver* horizontalMoveDriver;

public:
    HorizontalMoveUsecase(HorizontalMoveDriver* horizontalMoveDriver);

    bool moveHorizontally(Position position);
};
