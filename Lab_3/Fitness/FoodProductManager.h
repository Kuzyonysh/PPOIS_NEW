#pragma once
#include "FoodProduct.h"
#include "Exception.h"
#include <iostream>
using namespace std;


class FoodProductManager {
private:
    FoodProduct& product;

public:
    FoodProductManager() = default;
    FoodProductManager(FoodProduct& p);

    void consume(double amount);
    bool isLowStock(double threshold) const;
    double calculateTotalCalories() const;
    double getCaloriesForAmount(double amount) const;
    double estimateDaysLeft(double dailyConsumption) const;
    void refill(double amount);
};
