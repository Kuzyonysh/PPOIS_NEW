#pragma once
#include <iostream>
#include "ITemperatureSensor.h"
using namespace std;

class TemperatureController {
private:
    ITemperatureSensor& sensor;

public:
    TemperatureController(ITemperatureSensor& s);
    void measure(double temp);
    void checkSafety() const;
    void calibrate() const;
};

