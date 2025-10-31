#include "Recipe.h"

Recipe::Recipe(const string& n, const string& instr, int t)
    : name(n), instruction(instr), cookingTime(t),
    cuisineType(""), difficultyLevel(""), servings(1),
    chefName(""), notes(""), isVegetarian(false) {}

string Recipe::getName() const { return name; }
int Recipe::getCookingTime() const { return cookingTime; }
const vector<Ingredient>& Recipe::getIngredients() const { return ingredients; }
string Recipe::getInstruction() const { return instruction; }
string Recipe::getCuisineType() const { return cuisineType; }
string Recipe::getDifficultyLevel() const { return difficultyLevel; }
int Recipe::getServings() const { return servings; }
string Recipe::getChefName() const { return chefName; }
string Recipe::getNotes() const { return notes; }
bool Recipe::getIsVegetarian() const { return isVegetarian; }

void Recipe::setCuisineType(const string& c) { cuisineType = c; }
void Recipe::setDifficultyLevel(const string& d) { difficultyLevel = d; }
void Recipe::setServings(int s) { servings = s; }
void Recipe::setChefName(const string& n) { chefName = n; }
void Recipe::setNotes(const string& n) { notes = n; }
void Recipe::setVegetarian(bool v) { isVegetarian = v; }

void Recipe::addIngredientInternal(const Ingredient& ingr) {
    ingredients.push_back(ingr);
}
