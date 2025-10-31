#include "TemperatureController.h"

TemperatureController::TemperatureController(ITemperatureSensor& s) : sensor(s) {}

void TemperatureController::measure(double temp) {
    sensor.setCurrentTemperature(temp);
    cout << "Measured temperature: " << sensor.getCurrentTemperature() << " °C" << endl;
}

void TemperatureController::checkSafety() const {
    if (sensor.getCurrentTemperature() >= sensor.getMinSafe() &&
        sensor.getCurrentTemperature() <= sensor.getMaxSafe()) {
        cout << "Temperature is within safe limits." << endl;
    }
    else {
        cout << "Warning! Temperature is outside safe limits!" << endl;
    }
}

void TemperatureController::calibrate() const {
    cout << "Calibrating sensor at location: " << sensor.getSensorLocation() << endl;
}
