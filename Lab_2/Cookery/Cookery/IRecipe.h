#pragma once
#include <string>
#include <vector>
#include "Ingredient.h"
using namespace std;

class IRecipe {
public:
    virtual ~IRecipe() = default;

    virtual string getName() const = 0;
    virtual int getCookingTime() const = 0;
    virtual const vector<Ingredient>& getIngredients() const = 0;
    virtual string getInstruction() const = 0;
    virtual string getCuisineType() const = 0;
    virtual string getDifficultyLevel() const = 0;
    virtual int getServings() const = 0;
    virtual string getChefName() const = 0;
    virtual string getNotes() const = 0;
    virtual bool getIsVegetarian() const = 0;
};


