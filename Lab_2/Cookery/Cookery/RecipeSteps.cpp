#include "RecipeSteps.h"

void RecipeSteps::addStep(unique_ptr<IStep> step) {
    steps.push_back(std::move(step));
}

const vector<unique_ptr<IStep>>& RecipeSteps::getSteps() const {
    return steps;
}

int RecipeSteps::getTotalTime() const {
    int total = 0;
    for (const auto& s : steps)
        total += s->getTime();
    return total;
}
