#include "Menu.h"

Menu::Menu(string n, string desc)
    : name(n), description(desc), averagePrice(0.0) {}

const vector<Dish>& Menu::getDishes() const { return dishes; }
string Menu::getName() const { return name; }
string Menu::getDescription() const { return description; }
double Menu::getAveragePrice() const { return averagePrice; }

void Menu::setName(const string& n) { name = n; }
void Menu::setDescription(const string& desc) { description = desc; }
void Menu::setAveragePrice(double price) { averagePrice = price; }

void Menu::addDish(const Dish& d) { dishes.push_back(d); }

vector<Dish> Menu::getByCategory(const string& categoryName) const {
    vector<Dish> result;
    for (const auto& d : dishes) {
        if (d.getCategoryName() == categoryName) {
            result.push_back(d);
        }
    }
    return result;
}

bool Menu::hasDish(const string& name) const {
    for (const auto& d : dishes) {
        if (d.getName() == name) {
            return true;
        }
    }
    return false;
}
