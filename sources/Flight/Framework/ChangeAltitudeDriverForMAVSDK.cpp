#include <chrono>
#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <iostream>
#include <thread>
#include "Flight/Framework/ChangeAltitudeDriverForMAVSDK.h"

using namespace mavsdk;
using std::chrono::seconds;
using std::this_thread::sleep_for;

ChangeAltitudeDriverForMAVSDK::ChangeAltitudeDriverForMAVSDK(Mavsdk* mavsdk) {
    this->mavsdk = mavsdk;
}

ChangeAltitudeDriverProtocol::~ChangeAltitudeDriverProtocol() {}

bool ChangeAltitudeDriverForMAVSDK::changeAltitude(int targetAltitude, Position currentPosition)
{
    if (!mavsdk->is_connected()) {
        std::cout << "aircraft is not connected" << std::endl;
        return false;
    }
    auto system = this->mavsdk->systems()[0];
    auto action = Action{system};
    auto telemetry = Telemetry{system};

    // TODO: investigate and remove (workaround for avoiding crash)
    sleep_for(seconds(1));

    auto targetAbsoluteAltitude = currentPosition.absoluteAltitude + targetAltitude - currentPosition.relativeAltitude;
    const Action::Result ChangeAltitude_result = action.goto_location(
                currentPosition.latitude,
                currentPosition.longitude,
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
