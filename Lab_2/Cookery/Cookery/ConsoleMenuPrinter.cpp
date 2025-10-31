#include "ConsoleMenuPrinter.h"

void ConsoleMenuPrinter::print(const Menu& menu) const {
    const auto& dishes = menu.getDishes();

    cout << "Menu: " << menu.getName() << endl;
    cout << "Description: " << menu.getDescription() << endl;

    if (dishes.empty()) {
        cout << "The menu is empty." << endl;
        return;
    }

    cout << "\nDishes:\n";
    for (const auto& d : dishes) {
        cout << " - " << d.getName()
            << " (" << d.getCategoryName() << ", "
            << d.getCalories() << " kcal)" << endl;
    }

    cout << "\nAverage price: " << menu.getAveragePrice() << endl;
}
