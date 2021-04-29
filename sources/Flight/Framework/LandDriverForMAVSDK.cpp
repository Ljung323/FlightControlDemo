#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <iostream>
#include "Flight/Framework/LandDriverForMAVSDK.h"

using namespace mavsdk;

LandDriverForMAVSDK::LandDriverForMAVSDK(Mavsdk* mavsdk) {
    this->mavsdk = mavsdk;
}

LandDriverProtocol::~LandDriverProtocol() {}

bool LandDriverForMAVSDK::land()
{
    if (!mavsdk->is_connected()) {
        std::cout << "aircraft is not connected" << std::endl;
        return false;
    }

    auto system = this->mavsdk->systems()[0];

    auto action = Action{system};

    const Action::Result land_result = action.land();
    if (land_result != Action::Result::Success) {
        std::cout << "Land failed:" << land_result << std::endl;
        return false;
    } else {
        return true;
    }
}
