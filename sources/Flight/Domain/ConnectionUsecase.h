#pragma once
#include "sources/Flight/Framework/ConnectionDriver.h"

class ConnectionUsecase
{
private:
    ConnectionDriver* connectionDriver;

public:
    ConnectionUsecase(ConnectionDriver* connectionDriver);

    bool connect();
};
