#pragma once
#include "Printer.h"
#include "Kitchen.h"
#include <iostream>
using namespace std;

class ConsoleKitchenPrinter : public Printer<Kitchen> {
public:
    void print(const Kitchen& kitchen) const override;
};
