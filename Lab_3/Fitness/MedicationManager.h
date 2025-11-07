#pragma once
#include <vector>
#include <string>
#include "Medication.h"
using namespace std;

class MedicationManager {
private:
    vector<Medication> meds;

public:
    MedicationManager() = default;

    void addMedication(const Medication& med);
    bool removeMedication(const string& name);
    vector<Medication> getAllMedications() const;
};
