#pragma once
#include "WaterIntake.h"
#include "Exception.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class WaterIntakeManager {
private:
    WaterIntake& intake;

public:
    WaterIntakeManager() = default;
    WaterIntakeManager(WaterIntake& i);

    void addWater(double portion);
    bool checkNorm() const;
    void printProgress() const;
    void remindToDrink() const;
    void resetAmount();
};
