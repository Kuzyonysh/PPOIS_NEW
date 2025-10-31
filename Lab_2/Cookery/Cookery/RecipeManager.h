#pragma once
#include <string>
#include "Recipe.h"
#include "Exceptions.h"
#include "Printer.h"

class RecipeManager {
public:
    void addIngredient(Recipe& recipe, const Ingredient& ingr) const;
    void cook(const IRecipe& recipe) const;
    void removeRecipe(const std::string& recipeName) const;
    void findRecipe(const std::string& recipeName) const;
};
