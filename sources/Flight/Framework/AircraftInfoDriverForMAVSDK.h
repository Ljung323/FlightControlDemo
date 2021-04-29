#pragma once
#include <mavsdk/mavsdk.h>
#include <thread>
#include "Flight/Presentation/DriverProtocol/AircraftInfoDriverProtocol.h"
#include "Flight/Domain/Position.h"

using namespace mavsdk;

class AircraftInfoDriverForMAVSDK: public AircraftInfoDriverProtocol
{
private:
    Mavsdk* mavsdk;
    std::thread subscribeThread;

    void subscribe();

public:
    AircraftInfoDriverForMAVSDK(Mavsdk* mavsdk);
    ~AircraftInfoDriverForMAVSDK() override;

    void startSubscribe() override;
};
