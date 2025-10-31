#pragma once
#include <iostream>
#include "Printer.h"
#include "IInventory.h"
using namespace std;

class InventoryPrinter : public Printer<IInventory> {
public:
    void print(const IInventory& inventory) const override;
};
