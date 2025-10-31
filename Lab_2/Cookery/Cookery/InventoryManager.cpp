#include "InventoryManager.h"

InventoryManager::InventoryManager(IInventory& inv) : inventory(inv) {}

bool InventoryManager::add(const Ingredient& ing) {
    if (inventory.size() >= inventory.getCapacity()) {
        cout << "Inventory is full! Can't add " << ing.getName() << endl;
        return false;
    }
    inventory.addIngredient(ing);
    cout << "Added ingredient: " << ing.getName() << endl;
    return true;
}

bool InventoryManager::isFull() const {
    return inventory.size() >= inventory.getCapacity();
}

int InventoryManager::freeSpace() const {
    return inventory.getCapacity() - inventory.size();
}

bool InventoryManager::hasIngredient(const string& name) const {
    for (const auto& ing : inventory.getIngredients()) {
        if (ing.getName() == name)
            return true;
    }
    return false;
}

void InventoryManager::clearInventory() {
    cout << "Clearing inventory (demo, not actually implemented)" << endl;
}
