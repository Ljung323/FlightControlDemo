#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <iostream>
#include "Flight/Framework/TakeoffDriverForMAVSDK.h"

using namespace mavsdk;

TakeoffDriverForMAVSDK::TakeoffDriverForMAVSDK(Mavsdk* mavsdk) {
    this->mavsdk = mavsdk;
}

TakeoffDriverProtocol::~TakeoffDriverProtocol() {}

bool TakeoffDriverForMAVSDK::takeoff()
{
    if (!mavsdk->is_connected()) {
        std::cout << "aircraft is not connected" << std::endl;
        return false;
    }
    auto system = this->mavsdk->systems()[0];

    auto action = Action{system};
    const Action::Result arm_result = action.arm();

    if (arm_result != Action::Result::Success) {
        std::cout << "Arming failed:" << arm_result << std::endl;
        return false;
    }

    const Action::Result takeoff_result = action.takeoff();
    if (takeoff_result != Action::Result::Success) {
        std::cout << "Takeoff failed:" << takeoff_result << std::endl;
        return false;
    } else {
        return true;
    }
}
