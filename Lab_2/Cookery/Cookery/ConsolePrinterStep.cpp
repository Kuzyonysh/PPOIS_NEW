#include "ConsolePrinterStep.h"

void ConsolePrinterStep::print(const IStep& step) const {
    std::cout << "Step:" << std::endl;
    std::cout << "Action: " << step.getAction() << std::endl;
    std::cout << "Time: " << step.getTime() << " min" << std::endl;
}

void ConsolePrinterStep::print(const RecipeSteps& recipe) const {
    std::cout << "All steps:" << std::endl;
    for (const auto& s : recipe.getSteps()) {
        print(*s);
    }
    std::cout << "Total time: " << recipe.getTotalTime() << " min" << std::endl;
}
