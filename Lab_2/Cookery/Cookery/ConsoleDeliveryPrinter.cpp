#include "ConsoleDeliveryPrinter.h"

ConsoleDeliveryPrinter::ConsoleDeliveryPrinter(DeliveryCalculator& cal)
    : calculator(cal) {}

void ConsoleDeliveryPrinter::print(const IDelivery& d) const {
    cout << "Delivery characteristics:" << endl;
    cout << "Distance: " << d.getDistance() << " km" << endl;
    cout << "Weight: " << d.getWeight() << " kg" << endl;
    cout << "Speed: " << d.getSpeed() << " km/h" << endl;
    cout << "Base rate: " << d.getBaseRate() << " BYN/km" << endl;
    cout << "Estimated time: " << calculator.calculateTime(d) << " h" << endl;
    cout << "Cost: " << calculator.calculateCost(d) << " BYN" << endl;
    cout << "Status: " << d.getStatus() << endl;
}

void ConsoleDeliveryPrinter::printAll(const vector<IDelivery*>& deliveries) const {
    cout << "\nAll deliveries:\n";
    for (const auto& d : deliveries) {
        print(*d);
        cout << "--------------------------\n";
    }
    calculator.averageDeliveryTime(deliveries);
}
