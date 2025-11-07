#include "PrinterGoal.h"
#include <iostream>
using namespace std;

void PrinterGoal::print(const Goal& g) const {
    cout << g.getName() << ": " << g.getCurrent() << "/" << g.getTarget()
        << " " << g.getUnit() << (g.isAchieved() ? " (achieved)" : " (pending)") << endl;
}
