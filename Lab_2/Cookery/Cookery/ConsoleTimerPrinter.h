#pragma once
#include <iostream>
#include "Printer.h"
#include "Timer.h"
using namespace std;

class ConsoleTimerPrinter : public Printer<Timer> {
public:
    void print(const Timer& timer) const override;
};
