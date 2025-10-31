#pragma once
#include <iostream>
#include "Printer.h"
#include "ICook.h"

class ConsoleCookPrinter : public Printer<ICook> {
public:
    void print(const ICook& cook) const override;
};
