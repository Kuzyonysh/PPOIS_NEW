#include "Delivery.h"

Delivery::Delivery(double d, double w, double s, double b, string sts)
    : distance(d), weight(w), speed(s), baseRate(b), status(sts) {}

double Delivery::getDistance() const { return distance; }
double Delivery::getWeight() const { return weight; }
double Delivery::getBaseRate() const { return baseRate; }
double Delivery::getSpeed() const { return speed; }
string Delivery::getStatus() const { return status; }

void Delivery::setStatus(const string& newStatus) { status = newStatus; }
