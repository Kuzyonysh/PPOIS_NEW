#pragma once
#include "WaterIntake.h"
#include "WaterIntakeManager.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class PrinterWater : public Printer<WaterIntake> {
private:
    const WaterIntakeManager& manager;
public:
    PrinterWater(const WaterIntakeManager& m);
    void print(const WaterIntake& water) const override;
};
