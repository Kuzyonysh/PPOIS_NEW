#pragma once
#include <vector>
#include <memory>
#include "IStep.h"
using namespace std;

class RecipeSteps {
private:
    vector<unique_ptr<IStep>> steps;

public:
    void addStep(unique_ptr<IStep> step);
    const vector<unique_ptr<IStep>>& getSteps() const;
    int getTotalTime() const;

    ~RecipeSteps() = default;
};