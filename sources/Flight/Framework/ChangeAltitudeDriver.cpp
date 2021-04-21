#include <chrono>
#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <iostream>
#include <thread>
#include "sources/Flight/Framework/ChangeAltitudeDriver.h"

using namespace mavsdk;
using std::chrono::seconds;
using std::this_thread::sleep_for;

ChangeAltitudeDriver::ChangeAltitudeDriver(Mavsdk* mavsdk) {
    this->mavsdk = mavsdk;
}

ChangeAltitudeDriverProtocol::~ChangeAltitudeDriverProtocol() {}

bool ChangeAltitudeDriver::changeAltitude(int targetAltitude)
{
    if (!mavsdk->is_connected()) {
        std::cout << "aircraft is not connected" << std::endl;
        return false;
    }
    auto system = this->mavsdk->systems()[0];

    auto telemetry = Telemetry{system};
    const Telemetry::Result set_rate_result = telemetry.set_rate_position(1.0);
    if (set_rate_result != Telemetry::Result::Success) {
        std::cout << "Setting rate failed:" << set_rate_result << std::endl;
        return false;
    }

    telemetry.subscribe_position([](Telemetry::Position position) {
        std::cout << "position: " << position << std::endl;
    });

    sleep_for(seconds(1));

    // TODO: remove sleep_for and execute following statements as closure inside telemetry.subscribe_position
    auto position = telemetry.position();
    auto action = Action{system};
    auto targetAbsoluteAltitude = position.absolute_altitude_m + targetAltitude - position.relative_altitude_m;
    const Action::Result ChangeAltitude_result = action.goto_location(
                position.latitude_deg,
                position.longitude_deg,
                targetAbsoluteAltitude,
                telemetry.attitude_euler().yaw_deg
                );
    if (ChangeAltitude_result != Action::Result::Success) {
        std::cout << "ChangeAltitude failed:" << ChangeAltitude_result << std::endl;
        return false;
    } else {
        return true;
    }
}
