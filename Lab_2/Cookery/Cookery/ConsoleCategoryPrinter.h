#pragma once
#include "Printer.h"
#include "ICategory.h"
#include <iostream>
using namespace std;

class ConsoleCategoryPrinter : public Printer<ICategory> {
public:
    void print(const ICategory& category) const override;
};
