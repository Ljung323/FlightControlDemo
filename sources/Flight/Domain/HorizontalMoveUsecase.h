#pragma once
#include "sources/Flight/Framework/HorizontalMoveDriverForMAVSDK.h"
#include "sources/Flight/Domain/Position.h"

class HorizontalMoveUsecase
{
private:
    HorizontalMoveDriverProtocol* horizontalMoveDriver;

public:
    HorizontalMoveUsecase(HorizontalMoveDriverProtocol* horizontalMoveDriver);

    bool moveHorizontally(Position position);
};
