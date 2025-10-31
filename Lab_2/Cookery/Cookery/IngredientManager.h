#pragma once
#include "Ingredient.h"
#include "Exceptions.h"
#include <iostream>
using namespace std;

class IngredientManager {
private:
    Ingredient& ingredient;

public:
    explicit IngredientManager(Ingredient& ing);
    void decrease(double amount);
    void refill(double amount);
};

