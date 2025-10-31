#pragma once
#include "ICategory.h"
#include <string>
using namespace std;

class Category : public ICategory {
private:
    string name;
    string description;

    string cuisineType;
    int popularityLevel;
    bool vegetarian;
    int recommendedDishCount;

public:
    Category(const string& n, const string& d);

    string getName() const override;
    string getDescription() const override;
    void setDescription(const string& desc) override;
    bool matches(const string& otherCategory) const override;

    string getCuisineType() const override;
    void setCuisineType(const string& type);

    int getPopularityLevel() const override;
    void setPopularityLevel(int level);

    bool isVegetarian() const override;
    void setVegetarian(bool v);

    int getRecommendedDishCount() const override;
    void setRecommendedDishCount(int count);
};

