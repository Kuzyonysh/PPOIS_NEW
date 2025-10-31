#pragma once
#include <iostream>
#include "Printer.h"
#include "IDish.h"

class ConsoleDishPrinter : public Printer<IDish> {
public:
    void print(const IDish& dish) const override;
};

