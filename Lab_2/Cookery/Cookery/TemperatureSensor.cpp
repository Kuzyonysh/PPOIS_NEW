#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(double minTemp, double maxTemp, double c,
    string location, string type)
    : minSafeTemperature(minTemp), maxSafeTemperature(maxTemp),
    currentTemperature(c), sensorLocation(location), sensorType(type) {}

void TemperatureSensor::setCurrentTemperature(double temp) { currentTemperature = temp; }
double TemperatureSensor::getCurrentTemperature() const { return currentTemperature; }
double TemperatureSensor::getMinSafe() const { return minSafeTemperature; }
double TemperatureSensor::getMaxSafe() const { return maxSafeTemperature; }

void TemperatureSensor::setSensorLocation(const string& loc) { sensorLocation = loc; }
string TemperatureSensor::getSensorLocation() const { return sensorLocation; }

void TemperatureSensor::setSensorType(const string& type) { sensorType = type; }
string TemperatureSensor::getSensorType() const { return sensorType; }
