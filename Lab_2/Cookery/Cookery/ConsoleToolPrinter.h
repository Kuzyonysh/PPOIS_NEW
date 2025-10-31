#pragma once
#include "Tool.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class ConsoleToolPrinter : public Printer<Tool> {
public:
    void print(const Tool& tool) const override;
};

