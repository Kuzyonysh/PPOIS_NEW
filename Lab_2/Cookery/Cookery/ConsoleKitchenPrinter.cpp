#include "ConsoleKitchenPrinter.h"

void ConsoleKitchenPrinter::print(const Kitchen& kitchen) const {
    cout << "Kitchen: " << kitchen.getName() << endl;

    cout << "\nTools in the kitchen:\n";
    if (kitchen.getTools().empty()) {
        cout << "No tools available.\n";
    }
    else {
        for (const auto& t : kitchen.getTools()) {
            cout << "- " << t.getName() << endl;
        }
    }

    cout << "\nWorkplaces in the kitchen:\n";
    if (kitchen.getWorkplaces().empty()) {
        cout << "No workplaces.\n";
    }
    else {
        for (const auto& wp : kitchen.getWorkplaces()) {
            cout << "- " << wp << endl;
        }
    }

    cout << "\nStatus: " << (kitchen.isReady() ? "Ready for cooking!" : "Not ready!") << endl;
}
