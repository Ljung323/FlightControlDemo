#include "Flight/Domain/HorizontalMoveUsecase.h"
#include "Flight/Domain/Position.h"

HorizontalMoveUsecase::HorizontalMoveUsecase(HorizontalMoveDriverProtocol* horizontalMoveDriver) {
    this->horizontalMoveDriver = horizontalMoveDriver;
}

bool HorizontalMoveUsecase::moveHorizontally(Position position)
{
    return this->horizontalMoveDriver->moveHorizontally(position);
}
