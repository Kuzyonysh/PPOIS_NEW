#pragma once
#include "IDelivery.h"

class Delivery : public IDelivery {
private:
    double distance;
    double weight;
    double baseRate;
    double speed;
    string status;

public:
    Delivery(double d = 0, double w = 0, double s = 0, double b = 2, string sts = "Unknown");

    double getDistance() const override;
    double getWeight() const override;
    double getBaseRate() const override;
    double getSpeed() const override;
    string getStatus() const override;

    void setStatus(const string& newStatus) override;
};
