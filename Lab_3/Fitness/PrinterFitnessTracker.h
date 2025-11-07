#pragma once
#include "IFitnessTracker.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class PrinterFitnessTracker : public Printer<IFitnessTracker> {
public:
    void print(const IFitnessTracker& track) const override;
};
