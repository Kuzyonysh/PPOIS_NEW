#include "ConsoleRecipePrinter.h"

void ConsoleRecipePrinter::print(const Recipe& recipe) const {
    std::cout << "Recipe: " << recipe.getName() << std::endl;
    std::cout << "Cooking time: " << recipe.getCookingTime() << " min" << std::endl;
    std::cout << "Ingredients:" << std::endl;
    for (const auto& ingr : recipe.getIngredients()) {
        std::cout << " - " << ingr.getName() << std::endl;
    }
    std::cout << "Instructions: " << recipe.getInstruction() << std::endl;
}
