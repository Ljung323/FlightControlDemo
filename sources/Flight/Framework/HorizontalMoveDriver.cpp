#include <chrono>
#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <iostream>
#include <thread>
#include "sources/Flight/Framework/HorizontalMoveDriver.h"
#include "sources/Flight/Domain/Position.h"

using namespace mavsdk;
using std::chrono::seconds;
using std::this_thread::sleep_for;

HorizontalMoveDriver::HorizontalMoveDriver(Mavsdk* mavsdk) {
    this->mavsdk = mavsdk;
}

HorizontalMoveDriverProtocol::~HorizontalMoveDriverProtocol() {}

bool HorizontalMoveDriver::moveHorizontally(Position position)
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

    const Action::Result HorizontalMove_result = action.goto_location(
                position.latitude,
                position.longitude,
                position.absoluteAltitude,
                telemetry.attitude_euler().yaw_deg
                );
    if (HorizontalMove_result != Action::Result::Success) {
        std::cout << "HorizontalMove failed:" << HorizontalMove_result << std::endl;
        return false;
    } else {
        return true;
    }
}
