#include "PrinterChallenge.h"

void PrinterChallenge::print(const Challenge& c) const {
    cout << "Challenge Info" << endl;
    cout << "Name: " << c.getName() << endl;
    cout << "Description: " << c.getDescription() << endl;
    cout << "Progress: " << c.getProgress() << " / " << c.getTarget() << endl;
    cout << "Status: " << (c.isCompleted() ? "Completed" : "In Progress") << endl;
}
