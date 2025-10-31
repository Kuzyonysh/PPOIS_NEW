#include "Pan.h"

void Pan::setDiameter(double d) {
    if (d < 10 || d > 50)
        throw InvalidDiameterException("Invalid diameter: " + to_string(d));
    diameter = d;
}

void Pan::setTemperature(double t) {
    if (t < 0 || t > 400)
        throw InvalidTemperatureException("Invalid temperature: " + to_string(t));
    temperature = t;
}
