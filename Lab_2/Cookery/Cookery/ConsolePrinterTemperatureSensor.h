#pragma once
#include <iostream>
#include "ITemperatureSensor.h"
#include "Printer.h"
using namespace std;

class ConsolePrinterTemperatureSensor : public Printer<ITemperatureSensor> {
public:
    void print(const ITemperatureSensor& sensor) const override;
};
