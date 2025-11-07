#pragma once
#include "Printer.h"
#include "Equipment.h"
#include <iostream>
using namespace std;

class PrinterEquipment : public Printer<Equipment> {
public:
    void print(const Equipment& e) const override;
};

