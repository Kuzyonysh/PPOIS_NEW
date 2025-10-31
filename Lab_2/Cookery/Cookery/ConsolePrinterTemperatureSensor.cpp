#include "ConsolePrinterTemperatureSensor.h"

void ConsolePrinterTemperatureSensor::print(const ITemperatureSensor& sensor) const {
    cout << "Sensor type: " << sensor.getSensorType() << endl;
    cout << "Sensor location: " << sensor.getSensorLocation() << endl;
    cout << "Current temperature: " << sensor.getCurrentTemperature() << " °C" << endl;
}
