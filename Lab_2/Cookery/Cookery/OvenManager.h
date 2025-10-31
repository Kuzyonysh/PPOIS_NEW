#pragma once
#include "Oven.h"
#include <iostream>
using namespace std;

class OvenManager {
public:
    void startCooking(Oven& oven) const;
    void stopCooking(Oven& oven) const;
    void openDoor(Oven& oven) const;
    void closeDoor(Oven& oven) const;
    void clean() const;
    void preheat(Oven& oven, double targetTemp);
    void resetSettings(Oven& oven) const;
    void testHeating(Oven& oven) const;
};
