#pragma once
#include "ITemperatureSensor.h"

class TemperatureSensor : public ITemperatureSensor {
private:
    double currentTemperature;
    double maxSafeTemperature;
    double minSafeTemperature;
    string sensorLocation;
    string sensorType;

public:
    TemperatureSensor(double minTemp = 0, double maxTemp = 100, double c = 0,
        string location = "Unknown", string type = "digital");

    void setCurrentTemperature(double temp) override;
    double getCurrentTemperature() const override;
    double getMinSafe() const override;
    double getMaxSafe() const override;

    void setSensorLocation(const string& loc);
    string getSensorLocation() const;

    void setSensorType(const string& type);
    string getSensorType() const;
};

