#pragma once
#include "INutrition.h"
#include "FoodProduct.h"
#include <vector>
using namespace std;

class MealRecord : public INutrition {
private:
    string mealType;
    string date;
    double calories;
    vector<FoodProduct> products;

public:
    MealRecord(const string& t, const string& d, double c);

    string getMealType() const override;
    string getData() const override;
    double getCalories() const override;

    void setMealType(const string& type) override;
    void setDate(const string& d) override;
    void setCalories(double c) override;

    void addProduct(const FoodProduct& product);
    vector<FoodProduct> getAllProducts() const;
};

