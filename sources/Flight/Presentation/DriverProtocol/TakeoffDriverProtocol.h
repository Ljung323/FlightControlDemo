#pragma once

class TakeoffDriverProtocol {
public:
    virtual ~TakeoffDriverProtocol() = 0;

    virtual bool takeoff() = 0;
};
