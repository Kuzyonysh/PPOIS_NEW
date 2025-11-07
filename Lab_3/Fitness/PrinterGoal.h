#pragma once
#include <iostream>
#include "Printer.h"
#include "Goal.h"
using namespace std;

class PrinterGoal : public Printer<Goal> {
public:
    void print(const Goal& g) const override;
};

