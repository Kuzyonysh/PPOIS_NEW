#pragma once
#include <iostream>
#include <string>
#include "IDish.h"
using namespace std;

class DishManager {
public:
    void addDish(const IDish& dish) const;
    void removeDish(const string& dishName) const;
    void findDish(const string& dishName) const;
};
