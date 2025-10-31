#pragma once
#include <string>
#include <vector>
#include "ICook.h"
#include "Dish.h"
using namespace std;

class Cook : public ICook {
private:
    string name;
    int skillLevel;
    vector<Dish> dishes;

    int experienceYears;
    string specialty;
    int age;
    int awards;
    bool isAvailable;

public:
    Cook(string n = "Unknown", int skill = 1);

    string getName() const override;
    int getSkillLevel() const override;
    const vector<Dish>& getDishes() const override;

    int getExperienceYears() const override;
    string getSpecialty() const override;
    int getAge() const override;
    int getAwards() const override;
    bool getIsAvailable() const override;

    void setName(const string& newName);
    void setSkillLevel(int newLevel);
    void setDishes(const vector<Dish>& newDishes);
    void addDish(const Dish& dish);
    void setExperienceYears(int y);
    void setSpecialty(const string& s);
    void setAge(int a);
    void setAwards(int a);
    void setIsAvailable(bool avail);
};

