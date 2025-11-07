#pragma once
#include <iostream>
#include "DailyPlan.h"
#include "DailyPlanManager.h"
#include "Printer.h"
using namespace std;

class PrinterDailyPlan : public Printer<DailyPlan> {
private:
    const DailyPlanManager& manager;

public:
    PrinterDailyPlan(const DailyPlanManager& m);
    void print(const DailyPlan& plan) const override;
};
