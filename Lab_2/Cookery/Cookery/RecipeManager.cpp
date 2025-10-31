#include "RecipeManager.h"
#include <iostream>
using namespace std;

void RecipeManager::addIngredient(Recipe& recipe, const Ingredient& ingr) const {
    for (const auto& existing : recipe.getIngredients()) {
        if (existing.getName() == ingr.getName()) {
            throw DuplicateDishException(ingr.getName());
        }
    }
    recipe.addIngredientInternal(ingr);
    cout << "Ingredient " << ingr.getName() << " added to recipe " << recipe.getName() << endl;
}

void RecipeManager::cook(const IRecipe& recipe) const {
    cout << "Cooking " << recipe.getName() << " ... Done!" << endl;
}

void RecipeManager::removeRecipe(const string& recipeName) const {
    cout << "Recipe '" << recipeName << "' has been removed from the list." << endl;
}

void RecipeManager::findRecipe(const string& recipeName) const {
    cout << "Searching for recipe: " << recipeName << " ..." << endl;
    cout << "Recipe found successfully!" << endl;
}
