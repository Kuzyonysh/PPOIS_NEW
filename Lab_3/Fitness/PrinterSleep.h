#pragma once
#include "SleepRecord.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class PrinterSleep : public Printer<SleepRecord> {
public:
    void print(const SleepRecord& sleep) const override;
};
