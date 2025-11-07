#pragma once
#include "BodyMetrics.h"
#include "BodyMetricsManager.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class PrinterBodyMetrics : public Printer<BodyMetrics> {
private:
    const BodyMetricsManager& manager;

public:
    PrinterBodyMetrics(const BodyMetricsManager& m);
    void print(const BodyMetrics& record) const override;
};

