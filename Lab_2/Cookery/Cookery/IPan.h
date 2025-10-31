#pragma once
#include <string>
using namespace std;

class IPan {
public:
    virtual ~IPan() = default;
    virtual double getTemperature() const = 0;
    virtual void setTemperature(double) = 0;
    virtual string getState() const = 0;
    virtual void setState(const string&) = 0;
};
