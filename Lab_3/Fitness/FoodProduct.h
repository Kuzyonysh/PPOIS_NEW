#pragma once
#include <string>
using namespace std;

class FoodProduct {
private:
    string name;
    double quantity;
    string unit;
    double caloriesPerUnit;
    double protein;
    double fat;
    double carbs;
    bool healthy;

public:
    FoodProduct(const string& n, double q, const string& u, double cal);

    string getName() const;
    double getQuantity() const;
    string getUnit() const;
    double getCaloriesPerUnit() const;
    double getProtein() const;
    double getFat() const;
    double getCarbs() const;
    bool isHealthy() const;

    void setQuantity(double q);
    void setCaloriesPerUnit(double cal);
    void setProtein(double p);
    void setFat(double f);
    void setCarbs(double c);
    void setHealthy(bool h);
};
