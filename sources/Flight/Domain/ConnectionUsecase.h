#pragma once
#include "sources/Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.h"

class ConnectionUsecase
{
private:
    ConnectionDriverProtocol* connectionDriver;

public:
    ConnectionUsecase(ConnectionDriverProtocol* connectionDriver);

    bool connect();
};
