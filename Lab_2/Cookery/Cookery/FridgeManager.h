#pragma once
#include <iostream>
#include <stdexcept>
#include "IFridge.h"
#include "ITemperatureSensor.h"
#include "Ingredient.h"
#include "Exceptions.h" 
using namespace std;

class FridgeManager {
private:
    ITemperatureSensor& sensor;
    int maxSafeTemp;

public:
    FridgeManager(ITemperatureSensor& s, int maxSafe);

    void turnOnOff(IFridge& fridge) const;
    void setTemperature(IFridge& fridge, double t) const;
    void addIngredient(IFridge& fridge, const Ingredient& i) const;
};
