#pragma once

class ConnectionDriverProtocol {
public:
    virtual ~ConnectionDriverProtocol() = 0;

    virtual bool connect() = 0;
};
