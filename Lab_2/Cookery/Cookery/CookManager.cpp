#include "CookManager.h"

void CookManager::improveSkill(Cook& cook) const {
    cook.setSkillLevel(cook.getSkillLevel() + 1);
    cout << cook.getName() << " has improved skill to level "
        << cook.getSkillLevel() << "!" << endl;
}

void CookManager::addDish(Cook& cook, const Dish& dish) const {
    for (const auto& existing : cook.getDishes()) {
        if (existing.getName() == dish.getName()) {
            throw DuplicateDishException("Dish already exists: " + dish.getName());
        }
    }
    cook.addDish(dish);
    cout << cook.getName() << " learned to cook: " << dish.getName() << endl;
}

void CookManager::canCook(const Cook& cook, const string& dishName) const {
    bool found = false;
    for (const auto& d : cook.getDishes()) {
        if (d.getName() == dishName) {
            found = true;
            break;
        }
    }
    cout << cook.getName() << (found ? " can " : " cannot ") << "cook " << dishName << "." << endl;
}

void CookManager::cookDish(Cook& cook, const string& dishName) const {
    bool found = false;
    for (const auto& d : cook.getDishes()) {
        if (d.getName() == dishName) {
            found = true;
            cout << cook.getName() << " is cooking " << dishName << "..." << endl;
            cout << "Dish ready! (" << d.getCalories() << " kcal)" << endl;
            break;
        }
    }
    if (!found) {
        throw DishNotFoundException("Dish not found: " + dishName);
    }
}
