#pragma once
#include <string>
using namespace std;

class ICategory {
public:
    virtual ~ICategory() = default;
    virtual string getName() const = 0;
    virtual string getDescription() const = 0;
    virtual void setDescription(const string& desc) = 0;
    virtual bool matches(const string& otherCategory) const = 0;

    virtual string getCuisineType() const = 0;
    virtual int getPopularityLevel() const = 0;
    virtual bool isVegetarian() const = 0;
    virtual int getRecommendedDishCount() const = 0;
};

