#pragma once

class ConnectionDriverProtocol {
public:
    virtual bool connect() = 0;
    virtual ~ConnectionDriverProtocol() = 0;
};
