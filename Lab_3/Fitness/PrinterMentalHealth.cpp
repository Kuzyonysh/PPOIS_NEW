#include "PrinterMentalHealth.h"

PrinterMentalHealth::PrinterMentalHealth(const MentalHealthManager& m) : manager(m) {}

void PrinterMentalHealth::print(const MoodRecord& record) const {
    cout << "Date: " << record.getDate() << endl;
    cout << "Mood: " << record.getMood() << "/10" << endl;
    cout << "Stress: " << record.getStressLevel() << "/10" << endl;
    if (!record.getNote().empty())
        cout << "Note: " << record.getNote() << endl;
}
