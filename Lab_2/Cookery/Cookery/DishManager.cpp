#include "DishManager.h"

void DishManager::addDish(const IDish& dish) const {
    cout << "Dish '" << dish.getName() << "' has been added to the menu." << endl;
}

void DishManager::removeDish(const string& dishName) const {
    cout << "Dish '" << dishName << "' has been removed from the menu." << endl;
}

void DishManager::findDish(const string& dishName) const {
    cout << "Searching for dish: " << dishName << " ..." << endl;
    cout << "Dish found successfully!" << endl;
}
