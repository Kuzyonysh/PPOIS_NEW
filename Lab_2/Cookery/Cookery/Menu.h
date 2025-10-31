#pragma once
#include <vector>
#include <string>
#include "Dish.h"
using namespace std;

class Menu {
private:
    vector<Dish> dishes;
    string name;
    string description;
    double averagePrice;

public:
    Menu(string n = "Default Menu", string desc = "");

    const vector<Dish>& getDishes() const;
    string getName() const;
    string getDescription() const;
    double getAveragePrice() const;

    void setName(const string& n);
    void setDescription(const string& desc);
    void setAveragePrice(double price);

    void addDish(const Dish& d);
    vector<Dish> getByCategory(const string& categoryName) const;
    bool hasDish(const string& name) const;
};
