#include <chrono>
#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <iostream>
#include <thread>
#include "Flight/Framework/AircraftInfoDriverForMAVSDK.h"
#include "Flight/Domain/Position.h"

using namespace mavsdk;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

AircraftInfoDriverForMAVSDK::AircraftInfoDriverForMAVSDK(Mavsdk* mavsdk): subscribeThread() {
    this->mavsdk = mavsdk;
}

AircraftInfoDriverForMAVSDK::~AircraftInfoDriverForMAVSDK() {}

AircraftInfoDriverProtocol::~AircraftInfoDriverProtocol() {}

void AircraftInfoDriverForMAVSDK::startSubscribe()
{
    this->subscribeThread = std::thread([this]() { this->subscribe(); });
}

void AircraftInfoDriverForMAVSDK::subscribe() {
    auto system = this->mavsdk->systems()[0];
    auto telemetry = Telemetry{system};

    const Telemetry::Result set_rate_position_result = telemetry.set_rate_position(1.0);
    if (set_rate_position_result != Telemetry::Result::Success) {
        std::cout << "Setting rate position failed:" << set_rate_position_result << std::endl;
    }
    telemetry.subscribe_position([this](Telemetry::Position position) {
        this->position = Position(
                    position.latitude_deg,
                    position.longitude_deg,
                    position.relative_altitude_m,
                    position.absolute_altitude_m
                    );
    });

    const Telemetry::Result set_rate_battery_result = telemetry.set_rate_battery(1.0);
    if (set_rate_battery_result != Telemetry::Result::Success) {
        std::cout << "Setting rate battery failed:" << set_rate_battery_result << std::endl;
    }
    telemetry.subscribe_battery([this](Telemetry::Battery battery){
        this->aircraftBattery = battery.remaining_percent;
    });

    const Telemetry::Result set_rate_in_air_result = telemetry.set_rate_in_air(1.0);
    if (set_rate_in_air_result != Telemetry::Result::Success) {
        std::cout << "Setting rate in air failed:" << set_rate_in_air_result << std::endl;
    }
    telemetry.subscribe_in_air([this](bool isInAir){
        this->isInAir = isInAir;
    });

    while(true) {
        sleep_for(milliseconds(1));
    }
}
