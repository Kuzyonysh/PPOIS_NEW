#pragma once
#include <vector>
#include <iostream>
#include "IDelivery.h"
using namespace std;

class DeliveryCalculator {
public:
    double calculateTime(const IDelivery& d) const;
    double calculateCost(const IDelivery& d) const;
    double estimateDelay(const IDelivery& d, double expectedSpeed) const;
    bool isPriority(const IDelivery& d, double weightThreshold) const;
    double calculateCostWithWeight(const IDelivery& d, double weightFactor) const;
    bool canDeliver(const IDelivery& d, double maxDistance) const;
    double averageDeliveryTime(const vector<IDelivery*>& deliveries) const;
};
