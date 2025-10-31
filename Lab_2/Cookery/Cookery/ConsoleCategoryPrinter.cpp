#include "ConsoleCategoryPrinter.h"

void ConsoleCategoryPrinter::print(const ICategory& category) const {
    cout << "Category: " << category.getName() << endl;
    cout << "Description: " << category.getDescription() << endl;
    cout << "Cuisine Type: " << category.getCuisineType() << endl;
    cout << "Popularity Level: " << category.getPopularityLevel() << endl;
    cout << "Vegetarian: " << (category.isVegetarian() ? "Yes" : "No") << endl;
    cout << "Recommended Dish Count: " << category.getRecommendedDishCount() << endl;
}
