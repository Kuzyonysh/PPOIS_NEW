#include "ConsoleFridgePrinter.h"

void ConsoleFridgePrinter::print(const IFridge& fridge) const {
    cout << "Fridge status:\n";
    cout << "State: " << fridge.getState() << endl;
    cout << "Temperature: " << fridge.getTemperature() << " °C\n";
}
