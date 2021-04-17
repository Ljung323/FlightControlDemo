#pragma once
#include <mavsdk/mavsdk.h>

using namespace mavsdk;

class ConnectionDriver
{
private:
    Mavsdk* mavsdk;

public:
    ConnectionDriver(Mavsdk* mavsdk);

    bool connect();
};
