#include "MealRecord.h"

MealRecord::MealRecord(const string& t, const string& d, double c)
    : mealType(t), date(d), calories(c) {}

string MealRecord::getMealType() const { return mealType; }
string MealRecord::getData() const { return date; }
double MealRecord::getCalories() const { return calories; }

void MealRecord::setMealType(const string& type) { mealType = type; }
void MealRecord::setDate(const string& d) { date = d; }
void MealRecord::setCalories(double c) { calories = c; }

void MealRecord::addProduct(const FoodProduct& product) { products.push_back(product); }
vector<FoodProduct> MealRecord::getAllProducts() const { return products; }
