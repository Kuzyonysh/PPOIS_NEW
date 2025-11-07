#include "PrinterMeal.h"

PrinterMeal::PrinterMeal(const MealRecordManager& m) : manager(m) {}

void PrinterMeal::print(const INutrition& meal) const {
    cout << "Type: " << meal.getMealType() << endl;
    cout << "Date: " << meal.getData() << endl;
    cout << "Calories: " << meal.getCalories() << endl;
}
