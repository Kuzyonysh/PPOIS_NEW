#pragma once
#include "Pan.h"
#include <iostream>
using namespace std;

class PanHeatingManager {
public:
    void heatUp(IPan& pan, double targetTemp) const;
    void coolDown(IPan& pan) const;
    void checkReady(const IPan& pan) const;
};

class PanCareManager {
public:
    void clean(IPan& pan) const;
    void inspect(const Pan& pan) const;
};

class PanStorageManager {
public:
    void cover(Pan& pan) const;
    void replaceLid(Pan& pan, bool newLid) const;
    void store(const Pan& pan) const;
};
