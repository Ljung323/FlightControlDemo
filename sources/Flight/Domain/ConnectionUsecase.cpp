#include "sources/Flight/Domain/ConnectionUsecase.h"

ConnectionUsecase::ConnectionUsecase(ConnectionDriverProtocol* connectionDriver) {
    this->connectionDriver = connectionDriver;
}

bool ConnectionUsecase::connect()
{
    return this->connectionDriver->connect();
}
