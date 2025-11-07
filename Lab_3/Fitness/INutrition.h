#pragma once
#include <string>
using namespace std;

class INutrition {
public:
    virtual ~INutrition() = default;

    virtual string getMealType() const = 0;
    virtual string getData() const = 0;
    virtual double getCalories() const = 0;

    virtual void setMealType(const string& type) = 0;
    virtual void setDate(const string& d) = 0;
    virtual void setCalories(double c) = 0;
};

