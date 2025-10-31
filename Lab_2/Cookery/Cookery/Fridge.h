#pragma once
#include "IFridge.h"

class Fridge : public IFridge {
private:
    double temperature;
    string state;
    int maxCapacity;
    Inventory& inventory;

public:
    Fridge(double t, int c, Inventory& inv, string s = "Off");

    double getTemperature() const override;
    string getState() const override;
    int getMaxCapacity() const override;
    Inventory& getInventory() override;

    void setTemperature(double t) override;
    void setState(const string& s) override;
};
