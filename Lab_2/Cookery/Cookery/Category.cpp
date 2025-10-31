#include "Category.h"

Category::Category(const string& n, const string& d)
    : name(n), description(d),
    cuisineType("Unknown"), popularityLevel(0),
    vegetarian(false), recommendedDishCount(0) {}

string Category::getName() const { return name; }
string Category::getDescription() const { return description; }
void Category::setDescription(const string& desc) { description = desc; }
bool Category::matches(const string& otherCategory) const { return name == otherCategory; }

string Category::getCuisineType() const { return cuisineType; }
void Category::setCuisineType(const string& type) { cuisineType = type; }

int Category::getPopularityLevel() const { return popularityLevel; }
void Category::setPopularityLevel(int level) { popularityLevel = level; }

bool Category::isVegetarian() const { return vegetarian; }
void Category::setVegetarian(bool v) { vegetarian = v; }

int Category::getRecommendedDishCount() const { return recommendedDishCount; }
void Category::setRecommendedDishCount(int count) { recommendedDishCount = count; }
