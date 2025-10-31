#pragma once
#include "Printer.h"
#include "Pan.h"
#include <iostream>
using namespace std;

class ConsolePanPrinter : public Printer<Pan> {
public:
    void print(const Pan& pan) const override;
};
