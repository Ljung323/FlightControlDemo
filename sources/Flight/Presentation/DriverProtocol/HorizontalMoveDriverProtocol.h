#pragma once
#include "sources/Flight/Domain/Position.h"

class HorizontalMoveDriverProtocol {
public:
    virtual ~HorizontalMoveDriverProtocol() = 0;

    virtual bool moveHorizontally(Position position) = 0;
};
