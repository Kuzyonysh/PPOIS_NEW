#include "Inventory.h"

Inventory::Inventory(int c, string n, string loc, string o, string updated)
    : capacity(c), name(n), location(loc), owner(o), lastUpdated(updated) {}

void Inventory::addIngredient(const Ingredient& i) {
    if (ingredients.size() < capacity) {
        ingredients.push_back(i);
    }
}

int Inventory::size() const { return ingredients.size(); }
int Inventory::getCapacity() const { return capacity; }
const vector<Ingredient>& Inventory::getIngredients() const { return ingredients; }

string Inventory::getName() const { return name; }
string Inventory::getLocation() const { return location; }
string Inventory::getOwner() const { return owner; }
string Inventory::getLastUpdated() const { return lastUpdated; }
