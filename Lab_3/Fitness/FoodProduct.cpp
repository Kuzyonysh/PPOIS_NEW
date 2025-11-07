#include "FoodProduct.h"

FoodProduct::FoodProduct(const string& n, double q, const string& u, double cal)
    : name(n), quantity(q), unit(u), caloriesPerUnit(cal),
    protein(0), fat(0), carbs(0), healthy(true) {}

string FoodProduct::getName() const { return name; }
double FoodProduct::getQuantity() const { return quantity; }
string FoodProduct::getUnit() const { return unit; }
double FoodProduct::getCaloriesPerUnit() const { return caloriesPerUnit; }
double FoodProduct::getProtein() const { return protein; }
double FoodProduct::getFat() const { return fat; }
double FoodProduct::getCarbs() const { return carbs; }
bool FoodProduct::isHealthy() const { return healthy; }

void FoodProduct::setQuantity(double q) { quantity = q; }
void FoodProduct::setCaloriesPerUnit(double cal) { caloriesPerUnit = cal; }
void FoodProduct::setProtein(double p) { protein = p; }
void FoodProduct::setFat(double f) { fat = f; }
void FoodProduct::setCarbs(double c) { carbs = c; }
void FoodProduct::setHealthy(bool h) { healthy = h; }
