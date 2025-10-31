#pragma once
#include <string>
#include "IDish.h"
#include "Category.h"
using namespace std;

class Dish : public IDish {
private:
    string name;
    double calories;
    Category category;

    string description;
    double price;
    int spicyLevel;
    bool isVegetarian;
    int preparationTime;

public:
    Dish(string n, double cl, const Category& ct);

    string getName() const override;
    double getCalories() const override;
    string getCategoryName() const override;

    string getDescription() const override;
    double getPrice() const override;
    int getSpicyLevel() const override;
    bool getIsVegetarian() const override;
    int getPreparationTime() const override;

    void setCalories(double c);
    void setDescription(const string& desc);
    void setPrice(double p);
    void setSpicyLevel(int s);
    void setIsVegetarian(bool v);
    void setPreparationTime(int t);
};
