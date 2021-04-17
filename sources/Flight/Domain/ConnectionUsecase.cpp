#include "sources/Flight/Domain/ConnectionUsecase.h"

ConnectionUsecase::ConnectionUsecase(ConnectionDriver* connectionDriver) {
    this->connectionDriver = connectionDriver;
}

bool ConnectionUsecase::connect()
{
    return this->connectionDriver->connect();
}
