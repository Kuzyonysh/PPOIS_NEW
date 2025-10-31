#pragma once
#include <vector>
#include <string>
#include "IInventory.h"

class Inventory : public IInventory {
private:
    vector<Ingredient> ingredients;
    int capacity;
    string name;
    string location;
    string owner;
    string lastUpdated;

public:
    Inventory(int c,
        string n = "Main Inventory",
        string loc = "Kitchen",
        string o = "Chef",
        string updated = "Today");

    void addIngredient(const Ingredient& i) override;
    int size() const override;
    int getCapacity() const override;
    const vector<Ingredient>& getIngredients() const override;

    string getName() const override;
    string getLocation() const override;
    string getOwner() const override;
    string getLastUpdated() const override;
};
