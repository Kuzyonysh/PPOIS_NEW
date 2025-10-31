#pragma once
#include <string>
using namespace std;

class IDish {
public:
    virtual ~IDish() = default;
    virtual string getName() const = 0;
    virtual double getCalories() const = 0;
    virtual string getCategoryName() const = 0;

    virtual string getDescription() const = 0;
    virtual double getPrice() const = 0;
    virtual int getSpicyLevel() const = 0;
    virtual bool getIsVegetarian() const = 0;
    virtual int getPreparationTime() const = 0;
};
