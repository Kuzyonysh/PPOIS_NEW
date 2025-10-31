#pragma once
#include <string>
#include <vector>
#include "Dish.h"
using namespace std;

class ICook {
public:
    virtual ~ICook() = default;

    virtual string getName() const = 0;
    virtual int getSkillLevel() const = 0;
    virtual const vector<Dish>& getDishes() const = 0;

    virtual int getExperienceYears() const = 0;
    virtual string getSpecialty() const = 0;
    virtual int getAge() const = 0;
    virtual int getAwards() const = 0;
    virtual bool getIsAvailable() const = 0;
};

