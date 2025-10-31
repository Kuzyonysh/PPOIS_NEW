#include "ConsoleTimerPrinter.h"

void ConsoleTimerPrinter::print(const Timer& timer) const {
    cout << "Timer Name: " << timer.getName() << endl;
    cout << "Status: " << (timer.running() ? "Running" : "Paused") << endl;
    cout << "Elapsed Time: " << timer.getElapsedTime() << " min" << endl;
    cout << "Limit: " << timer.getLimit() << " min" << endl;
    cout << "Over Limit: " << (timer.isOverLimit() ? "Yes" : "No") << endl;
}
