#include "PrinterSleep.h"

void PrinterSleep::print(const SleepRecord& sleep) const {
    cout << "Date: " << sleep.getDate() << endl;
    cout << "Hours: " << sleep.getHours() << endl;
    cout << "Quality: " << sleep.getQuality() << endl;
}

