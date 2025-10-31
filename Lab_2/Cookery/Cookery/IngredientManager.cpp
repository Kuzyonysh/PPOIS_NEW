#include "IngredientManager.h"

IngredientManager::IngredientManager(Ingredient& ing)
    : ingredient(ing) {}

void IngredientManager::decrease(double amount) {
    if (amount < 0)
        throw InvalidIngredientAmountException("Amount to decrease cannot be negative");

    if (amount > ingredient.getQuantity()) {
        ingredient.setQuantity(0);
        cout << "Not enough ingredient: " << ingredient.getName() << endl;
    }
    else {
        ingredient.setQuantity(ingredient.getQuantity() - amount);
    }
}

void IngredientManager::refill(double amount) {
    if (amount <= 0)
        throw InvalidIngredientAmountException("Refill amount must be positive for " + ingredient.getName());

    ingredient.setQuantity(ingredient.getQuantity() + amount);
    cout << "Replenished " << ingredient.getName()
        << " by " << amount << " " << ingredient.getUnit() << endl;
}
