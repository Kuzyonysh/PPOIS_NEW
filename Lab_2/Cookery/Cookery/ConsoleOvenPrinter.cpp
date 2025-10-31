#include "ConsoleOvenPrinter.h"
#include <iostream>

void ConsoleOvenPrinter::print(const Oven& oven) const {
    cout << "Oven status:" << endl;
    cout << "Temperature: " << oven.getTemperature() << "°C" << endl;
    cout << "Mode: " << (oven.getMode().empty() ? "not set" : oven.getMode()) << endl;
    cout << "Cooking time: " << oven.getCookingTime() << " min" << endl;
    cout << "Power state: " << (oven.getPowerState() ? "ON" : "OFF") << endl;
    cout << "Door closed: " << (oven.getDoorState() ? "Yes" : "No") << endl;
    cout << "Brand: " << oven.getBrand() << endl;
    cout << "Power: " << oven.getPower() << " kW" << endl;
    cout << "Color: " << oven.getColor() << endl;
    cout << "Material: " << oven.getMaterial() << endl;
    cout << "Capacity: " << oven.getCapacity() << " liters" << endl;
    cout << "Dimensions (WxHxD): " << oven.getWidth() << " x "
        << oven.getHeight() << " x " << oven.getDepth() << " cm" << endl;
    cout << "Has timer: " << (oven.hasTimerFunction() ? "Yes" : "No") << endl;
    cout << "Has light: " << (oven.hasLightFunction() ? "Yes" : "No") << endl;
}
