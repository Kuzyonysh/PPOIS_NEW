#include "Fridge.h"

Fridge::Fridge(double t, int c, Inventory& inv, string s)
    : temperature(t), maxCapacity(c), state(s), inventory(inv) {}

double Fridge::getTemperature() const { return temperature; }
string Fridge::getState() const { return state; }
int Fridge::getMaxCapacity() const { return maxCapacity; }
Inventory& Fridge::getInventory() { return inventory; }

void Fridge::setTemperature(double t) { temperature = t; }
void Fridge::setState(const string& s) { state = s; }
