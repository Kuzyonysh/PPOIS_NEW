#pragma once
#include "FoodProduct.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class FoodPrinter : public Printer<FoodProduct> {
public:
    void print(const FoodProduct& p) const override;
};
