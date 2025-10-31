#pragma once
#include "Ingredient.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class ConsoleIngredientPrinter : public Printer<Ingredient> {
public:
    void print(const Ingredient& ing) const override;
};

