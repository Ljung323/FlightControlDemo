#include <mavsdk/mavsdk.h>
#include <iostream>
#include <future>
#include "sources/Flight/Framework/ConnectionDriver.h"
#include "sources/Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.h"

using namespace mavsdk;
using std::chrono::seconds;
using std::this_thread::sleep_for;

ConnectionDriver::ConnectionDriver(Mavsdk* mavsdk) {
    this->mavsdk = mavsdk;
}

ConnectionDriverProtocol::~ConnectionDriverProtocol() {}

bool ConnectionDriver::connect()
{
    std::string connection_url = "udp://:14540";
    ConnectionResult connection_result;

    connection_result = this->mavsdk->add_any_connection(connection_url);

    if (connection_result != ConnectionResult::Success) {
        std::cout << "Connection failed: " << connection_result << std::endl;
        return false;
    }

    std::cout << "Waiting to discover system..." << std::endl;
    auto prom = std::promise<std::shared_ptr<System>>{};
    auto fut = prom.get_future();

    mavsdk->subscribe_on_new_system([this, &prom]() {
        auto system = this->mavsdk->systems().back();

        if (system->has_autopilot()) {
            std::cout << "Discovered autopilot" << std::endl;

            this->mavsdk->subscribe_on_new_system(nullptr);
            prom.set_value(system);
        }
    });

    if (fut.wait_for(seconds(3)) == std::future_status::timeout) {
        std::cout << "No autopilot found, exiting." << std::endl;
        return false;
    } else {
        std::cout << "autopilot found." << std::endl;
        return true;
    }
}
