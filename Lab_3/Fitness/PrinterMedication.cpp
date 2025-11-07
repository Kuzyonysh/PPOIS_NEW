#include "PrinterMedication.h"

PrinterMedication::PrinterMedication(const MedicationManager& m) : manager(m) {}

void PrinterMedication::print(const Medication& med) const {
    cout << "Name: " << med.getName() << endl;
    cout << "Dose: " << med.getDose() << endl;
    cout << "Frequency: " << med.getFrequency() << endl;
    cout << "Start: " << med.getStartDate() << ", End: " << med.getEndDate() << endl;
    if (!med.getNote().empty()) cout << "Note: " << med.getNote() << endl;
}

void PrinterMedication::printAll() const {
    for (const auto& med : manager.getAllMedications()) {
        print(med);
        cout << "------------------------" << endl;
    }
}
