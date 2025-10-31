#include "Dish.h"

Dish::Dish(string n, double cl, const Category& ct)
    : name(n), calories(cl), category(ct),
    description(""), price(0), spicyLevel(0),
    isVegetarian(false), preparationTime(0) {}

string Dish::getName() const { return name; }
double Dish::getCalories() const { return calories; }
string Dish::getCategoryName() const { return category.getName(); }

string Dish::getDescription() const { return description; }
double Dish::getPrice() const { return price; }
int Dish::getSpicyLevel() const { return spicyLevel; }
bool Dish::getIsVegetarian() const { return isVegetarian; }
int Dish::getPreparationTime() const { return preparationTime; }

void Dish::setCalories(double c) { calories = c; }
void Dish::setDescription(const string& desc) { description = desc; }
void Dish::setPrice(double p) { price = p; }
void Dish::setSpicyLevel(int s) { spicyLevel = s; }
void Dish::setIsVegetarian(bool v) { isVegetarian = v; }
void Dish::setPreparationTime(int t) { preparationTime = t; }
