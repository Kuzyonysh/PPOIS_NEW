#pragma once
#include "Printer.h"
#include "IOrder.h"
#include <iostream>
using namespace std;

class ConsoleOrderPrinter : public Printer<IOrder> {
public:
    void print(const IOrder& order) const override;
};

