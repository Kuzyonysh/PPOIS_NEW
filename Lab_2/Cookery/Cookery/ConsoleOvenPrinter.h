#pragma once
#include "Oven.h"
#include <iostream>
using namespace std;

class ConsoleOvenPrinter : public Printer<Oven> {
public:
    void print(const Oven& oven) const override;
};
