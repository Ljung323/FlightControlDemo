#pragma once
#include <mavsdk/mavsdk.h>
#include <thread>
#include "sources/Flight/Presentation/DriverProtocol/AircraftInfoDriverProtocol.h"
#include "sources/Flight/Domain/Position.h"

using namespace mavsdk;

class AircraftInfoDriver: public AircraftInfoDriverProtocol
{
private:
    Mavsdk* mavsdk;
    std::thread subscribeThread;

    void subscribe();

public:
    AircraftInfoDriver(Mavsdk* mavsdk);
    ~AircraftInfoDriver() override;

    void startSubscribe() override;
};
