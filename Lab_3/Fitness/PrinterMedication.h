#pragma once
#include <iostream>
#include "Printer.h"
#include "Medication.h"
#include "MedicationManager.h"
using namespace std;

class PrinterMedication : public Printer<Medication> {
private:
    const MedicationManager& manager;

public:
    PrinterMedication(const MedicationManager& m);
    void print(const Medication& med) const override;
    void printAll() const;
};
#pragma once
