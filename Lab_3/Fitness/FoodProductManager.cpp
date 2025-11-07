#include "FoodProductManager.h"
#include "Exception.h"

FoodProductManager::FoodProductManager(FoodProduct& p) : product(p) {}

void FoodProductManager::consume(double amount) {
    if (amount <= 0)
        throw InvalidIngredientAmountException("Amount must be positive");

    if (amount > product.getQuantity()) {
        product.setQuantity(0);
        cout << "Not enough " << product.getName() << " left." << endl;
    }
    else {
        product.setQuantity(product.getQuantity() - amount);
    }
}

bool FoodProductManager::isLowStock(double threshold) const {
    return product.getQuantity() < threshold;
}

double FoodProductManager::calculateTotalCalories() const {
    return product.getCaloriesPerUnit() * product.getQuantity();
}

double FoodProductManager::getCaloriesForAmount(double amount) const {
    if (amount <= 0)
        throw InvalidIngredientAmountException("Amount must be positive");
    return product.getCaloriesPerUnit() * amount;
}

double FoodProductManager::estimateDaysLeft(double dailyConsumption) const {
    if (dailyConsumption <= 0)
        throw InvalidIngredientAmountException("Daily consumption must be positive");
    return product.getQuantity() / dailyConsumption;
}

void FoodProductManager::refill(double amount) {
    if (amount <= 0)
        throw InvalidIngredientAmountException("Refill amount must be positive");
    product.setQuantity(product.getQuantity() + amount);
    cout << "Added " << amount << " " << product.getUnit() << " of " << product.getName() << endl;
}
