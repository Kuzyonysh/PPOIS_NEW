#include "InventoryPrinter.h"

void InventoryPrinter::print(const IInventory& inventory) const {
    cout << "Inventory Name: " << inventory.getName() << endl;
    cout << "Location: " << inventory.getLocation() << endl;
    cout << "Owner: " << inventory.getOwner() << endl;
    cout << "Last Updated: " << inventory.getLastUpdated() << endl;

    const auto& ingredients = inventory.getIngredients();
    if (ingredients.empty()) {
        cout << "No ingredients stored" << endl;
        return;
    }

    cout << "Ingredients in inventory:" << endl;
    for (const auto& ing : ingredients)
        cout << " - " << ing.getName() << endl;
}
