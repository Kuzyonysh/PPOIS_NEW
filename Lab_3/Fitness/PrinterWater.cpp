#include "PrinterWater.h"

PrinterWater::PrinterWater(const WaterIntakeManager& m) : manager(m) {}

void PrinterWater::print(const WaterIntake& water) const {
    cout << "Date: " << water.getDate() << endl;
    cout << "Amount: " << water.getAmount() << " ml" << endl;
    cout << "Daily Goal: " << water.getDailyGoal() << " ml" << endl;
    if (!water.getNote().empty())
        cout << "Note: " << water.getNote() << endl;
}
