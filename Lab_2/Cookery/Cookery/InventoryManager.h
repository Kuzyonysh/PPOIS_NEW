#pragma once
#include <iostream>
#include "IInventory.h"
using namespace std;

class InventoryManager {
private:
    IInventory& inventory;

public:
    InventoryManager(IInventory& inv);

    bool add(const Ingredient& ing);
    bool isFull() const;
    int freeSpace() const;
    bool hasIngredient(const string& name) const;
    void clearInventory();
};
