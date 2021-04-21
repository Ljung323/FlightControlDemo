#pragma once
#include <mavsdk/mavsdk.h>
#include "sources/Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.h"

using namespace mavsdk;

class ConnectionDriver: public ConnectionDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    ConnectionDriver(Mavsdk* mavsdk);

    bool connect() override;
};
