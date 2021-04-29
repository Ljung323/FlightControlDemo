#pragma once
#include <mavsdk/mavsdk.h>
#include "Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.h"

using namespace mavsdk;

class ConnectionDriverForMAVSDK: public ConnectionDriverProtocol
{
private:
    Mavsdk* mavsdk;

public:
    ConnectionDriverForMAVSDK(Mavsdk* mavsdk);

    bool connect() override;
};
