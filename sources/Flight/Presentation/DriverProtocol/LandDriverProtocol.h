#pragma once

class LandDriverProtocol {
public:
    virtual ~LandDriverProtocol() = 0;

    virtual bool land() = 0;
};
