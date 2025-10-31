#pragma once
#include "IKitchen.h"
#include "Exceptions.h"
#include <algorithm>
#include <iostream>
using namespace std;

class KitchenManager {
public:
    void addWorkplace(IKitchen& kitchen, const string& name) const;
    void addTool(IKitchen& kitchen, const Tool& tool) const;
    void renameKitchen(IKitchen& kitchen, const string& newName) const;
    void changeCapacity(IKitchen& kitchen, int newCapacity) const;
    void listTools(const IKitchen& kitchen) const;
    void listWorkplaces(const IKitchen& kitchen) const;
    bool checkReady(const IKitchen& kitchen) const;
};
