#pragma once
#include <iostream>
#include "Printer.h"
#include "Recipe.h"

class ConsoleRecipePrinter : public Printer<Recipe> {
public:
    void print(const Recipe& recipe) const override;
};

