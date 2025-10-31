#include "ConsoleDishPrinter.h"
#include <iostream>
using namespace std;

void ConsoleDishPrinter::print(const IDish& dish) const {
    cout << "Dish: " << dish.getName() << endl;
    cout << "Calories: " << dish.getCalories() << " kcal" << endl;
    cout << "Category: " << dish.getCategoryName() << endl;
    cout << "Description: " << dish.getDescription() << endl;
    cout << "Price: " << dish.getPrice() << " BYN" << endl;
    cout << "Spicy level: " << dish.getSpicyLevel() << endl;
    cout << "Vegetarian: " << (dish.getIsVegetarian() ? "Yes" : "No") << endl;
    cout << "Preparation time: " << dish.getPreparationTime() << " min" << endl;
}
