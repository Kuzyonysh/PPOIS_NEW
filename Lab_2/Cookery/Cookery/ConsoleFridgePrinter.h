#pragma once
#include <iostream>
#include "Printer.h"
#include "IFridge.h"
using namespace std;

class ConsoleFridgePrinter : public Printer<IFridge> {
public:
    void print(const IFridge& fridge) const override;
};
