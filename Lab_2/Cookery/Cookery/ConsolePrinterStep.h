#pragma once
#include "IStep.h"
#include "RecipeSteps.h"
#include <iostream>
using namespace std;

class ConsolePrinterStep {
public:
    void print(const IStep& step) const;
    void print(const RecipeSteps& recipe) const;
};
