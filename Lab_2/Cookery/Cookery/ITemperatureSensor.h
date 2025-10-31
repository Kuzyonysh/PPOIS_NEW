#pragma once
#include <string>
using namespace std;

class ITemperatureSensor {
public:
    virtual ~ITemperatureSensor() = default;
    virtual void setCurrentTemperature(double temp) = 0;
    virtual double getCurrentTemperature() const = 0;
    virtual double getMinSafe() const = 0;
    virtual double getMaxSafe() const = 0;
    virtual string getSensorLocation() const = 0;
    virtual string getSensorType() const = 0;
};
