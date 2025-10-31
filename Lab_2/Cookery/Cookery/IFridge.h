#pragma once
#include <string>
#include "Inventory.h"
using namespace std;

class IFridge {
public:
    virtual ~IFridge() = default;

    virtual double getTemperature() const = 0;
    virtual string getState() const = 0;
    virtual int getMaxCapacity() const = 0;
    virtual Inventory& getInventory() = 0;

    virtual void setTemperature(double t) = 0;
    virtual void setState(const string& s) = 0;
};

