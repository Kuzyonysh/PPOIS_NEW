#pragma once
#include <string>
#include <vector>
#include "Ingredient.h"
using namespace std;

class IInventory {
public:
    virtual ~IInventory() = default;
    virtual void addIngredient(const Ingredient& i) = 0;
    virtual int size() const = 0;
    virtual int getCapacity() const = 0;
    virtual const vector<Ingredient>& getIngredients() const = 0;
    virtual string getName() const = 0;
    virtual string getLocation() const = 0;
    virtual string getOwner() const = 0;
    virtual string getLastUpdated() const = 0;
};
