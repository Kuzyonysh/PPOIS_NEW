#include "KitchenManager.h"

void KitchenManager::addWorkplace(IKitchen& kitchen, const string& name) const {
    const auto& existing = kitchen.getWorkplaces();
    if (find(existing.begin(), existing.end(), name) != existing.end()) {
        throw DuplicateWorkplaceException("Workplace already exists: " + name);
    }
    kitchen.addWorkplace(name);
    cout << "Workplace '" << name << "' added to kitchen '" << kitchen.getName() << "'.\n";
}

void KitchenManager::addTool(IKitchen& kitchen, const Tool& tool) const {
    kitchen.addTool(tool);
    cout << "Tool '" << tool.getName() << "' added to kitchen '" << kitchen.getName() << "'.\n";
}

void KitchenManager::renameKitchen(IKitchen& kitchen, const string& newName) const {
    kitchen.setName(newName);
    cout << "Kitchen renamed to '" << kitchen.getName() << "'.\n";
}

void KitchenManager::changeCapacity(IKitchen& kitchen, int newCapacity) const {
    kitchen.setCapacity(newCapacity);
    cout << "Kitchen capacity set to " << newCapacity << ".\n";
}

void KitchenManager::listTools(const IKitchen& kitchen) const {
    cout << "Tools in kitchen '" << kitchen.getName() << "':\n";
    for (const auto& t : kitchen.getTools())
        cout << "- " << t.getName() << "\n";
    if (kitchen.getTools().empty()) cout << "No tools.\n";
}

void KitchenManager::listWorkplaces(const IKitchen& kitchen) const {
    cout << "Workplaces in kitchen '" << kitchen.getName() << "':\n";
    for (const auto& wp : kitchen.getWorkplaces())
        cout << "- " << wp << "\n";
    if (kitchen.getWorkplaces().empty()) cout << "No workplaces.\n";
}

bool KitchenManager::checkReady(const IKitchen& kitchen) const {
    if (kitchen.isReady()) {
        cout << "Kitchen '" << kitchen.getName() << "' is ready!\n";
        return true;
    }
    else {
        cout << "Kitchen '" << kitchen.getName() << "' is not ready.\n";
        return false;
    }
}
