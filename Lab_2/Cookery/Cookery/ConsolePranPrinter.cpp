#include "ConsolePanPrinter.h"
#include <iostream>

void ConsolePanPrinter::print(const Pan& pan) const {
    cout << "Material: " << pan.getMaterial() << endl;
    cout << "Diameter: " << pan.getDiameter() << " cm" << endl;
    cout << "State: " << pan.getState() << endl;
    cout << "Depth: " << pan.getDepth() << " cm" << endl;
    cout << "Weight: " << pan.getWeight() << " kg" << endl;
    cout << "Temperature: " << pan.getTemperature() << "°C" << endl;
    cout << "Has Lid: " << (pan.getHasLid() ? "Yes" : "No") << endl;
}
