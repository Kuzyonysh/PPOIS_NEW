#include "FoodPrinter.h"

void FoodPrinter::print(const FoodProduct& p) const {
    cout << "Food: " << p.getName() << endl;
    cout << "Quantity: " << p.getQuantity() << " " << p.getUnit() << endl;
    cout << "Calories per " << p.getUnit() << ": " << p.getCaloriesPerUnit() << " kcal" << endl;
    cout << "Total Calories: " << p.getCaloriesPerUnit() * p.getQuantity() << " kcal" << endl;
    cout << "Macros (P/F/C): " << p.getProtein() << "/" << p.getFat() << "/" << p.getCarbs() << endl;
    cout << (p.isHealthy() ? "Healthy choice" : "Not very healthy") << endl;
}
