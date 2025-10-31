#include "DeliveryCalculator.h"

double DeliveryCalculator::calculateTime(const IDelivery& d) const {
    if (d.getSpeed() == 0) {
        cout << "Error: speed cannot be zero.\n";
        return 0;
    }
    double time = d.getDistance() / d.getSpeed();
    cout << "Delivery time: " << time << " h" << endl;
    return time;
}

double DeliveryCalculator::calculateCost(const IDelivery& d) const {
    double cost = d.getDistance() * d.getBaseRate();
    cout << "Delivery cost: " << cost << " BYN" << endl;
    return cost;
}

double DeliveryCalculator::estimateDelay(const IDelivery& d, double expectedSpeed) const {
    double delay = abs((expectedSpeed - d.getSpeed()) * d.getDistance() / expectedSpeed);
    cout << "Estimated delay: " << delay << " h" << endl;
    return delay;
}

bool DeliveryCalculator::isPriority(const IDelivery& d, double weightThreshold) const {
    bool priority = d.getWeight() > weightThreshold;
    cout << "Delivery " << (priority ? "is" : "is not") << " a priority." << endl;
    return priority;
}

double DeliveryCalculator::calculateCostWithWeight(const IDelivery& d, double weightFactor) const {
    double cost = (d.getDistance() * d.getBaseRate()) + (d.getWeight() * weightFactor);
    cout << "Delivery cost with weight factor: " << cost << " BYN" << endl;
    return cost;
}

bool DeliveryCalculator::canDeliver(const IDelivery& d, double maxDistance) const {
    bool possible = d.getDistance() <= maxDistance;
    cout << "Delivery " << (possible ? "can" : "cannot") << " be made." << endl;
    return possible;
}

double DeliveryCalculator::averageDeliveryTime(const vector<IDelivery*>& deliveries) const {
    if (deliveries.empty()) return 0;
    double totalTime = 0;
    for (const auto& d : deliveries)
        totalTime += d->getDistance() / d->getSpeed();
    double avg = totalTime / deliveries.size();
    cout << "Average delivery time: " << avg << " h" << endl;
    return avg;
}
