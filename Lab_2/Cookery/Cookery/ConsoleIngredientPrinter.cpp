#include "ConsoleIngredientPrinter.h"

void ConsoleIngredientPrinter::print(const Ingredient& ing) const {
    cout << "Ingredient: " << ing.getName() << endl;
    cout << "Quantity: " << ing.getQuantity() << endl;
    cout << "Unit: " << ing.getUnit() << endl;
}
