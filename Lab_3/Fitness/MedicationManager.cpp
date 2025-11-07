#include "MedicationManager.h"

void MedicationManager::addMedication(const Medication& med) {
    meds.push_back(med);
}

bool MedicationManager::removeMedication(const string& name) {
    auto it = remove_if(meds.begin(), meds.end(),
        [&](const Medication& m) { return m.getName() == name; });

    if (it != meds.end()) {
        meds.erase(it, meds.end());
        return true;
    }
    return false;
}

vector<Medication> MedicationManager::getAllMedications() const {
    return meds;
}
