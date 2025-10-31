#pragma once
#include "IRecipe.h"

class Recipe : public IRecipe {
private:
    string name;
    vector<Ingredient> ingredients;
    string instruction;
    int cookingTime;

    string cuisineType;
    string difficultyLevel;
    int servings;
    string chefName;
    string notes;
    bool isVegetarian;

public:
    Recipe(const string& n, const string& instr, int t);

    string getName() const override;
    int getCookingTime() const override;
    const vector<Ingredient>& getIngredients() const override;
    string getInstruction() const override;

    string getCuisineType() const override;
    string getDifficultyLevel() const override;
    int getServings() const override;
    string getChefName() const override;
    string getNotes() const override;
    bool getIsVegetarian() const override;

    void setCuisineType(const string& c);
    void setDifficultyLevel(const string& d);
    void setServings(int s);
    void setChefName(const string& n);
    void setNotes(const string& n);
    void setVegetarian(bool v);

    void addIngredientInternal(const Ingredient& ingr);
};


