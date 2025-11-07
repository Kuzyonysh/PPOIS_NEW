#pragma once
#include "Printer.h"
#include "HealthReport.h"
#include <iostream>
using namespace std;

class PrinterHealthReport : public Printer<HealthReport> {
public:
    void print(const HealthReport& r) const override;
};
