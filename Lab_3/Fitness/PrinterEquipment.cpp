#include "PrinterEquipment.h"

void PrinterEquipment::print(const Equipment& e) const {
    cout << "Equipment: " << endl;
    cout << "Name: " << e.getName() << endl;
    cout << "Type: " << e.getType() << endl;
    cout << "Availability: " << (e.getAvailability() ? "Available" : "Not available") << endl;
}
