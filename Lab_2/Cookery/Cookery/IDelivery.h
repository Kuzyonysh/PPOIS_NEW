#pragma once
#include <string>
using namespace std;

class IDelivery {
public:
    virtual ~IDelivery() = default;
    virtual double getDistance() const = 0;
    virtual double getWeight() const = 0;
    virtual double getBaseRate() const = 0;
    virtual double getSpeed() const = 0;
    virtual string getStatus() const = 0;
    virtual void setStatus(const string& newStatus) = 0;
};
