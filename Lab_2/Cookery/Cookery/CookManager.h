#pragma once
#include <iostream>
#include <string>
#include "Cook.h"
#include "Exceptions.h"
using namespace std;

class CookManager {
public:
    void improveSkill(Cook& cook) const;
    void addDish(Cook& cook, const Dish& dish) const;
    void canCook(const Cook& cook, const string& dishName) const;
    void cookDish(Cook& cook, const string& dishName) const;
};

