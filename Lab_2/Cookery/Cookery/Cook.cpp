#include "Cook.h"

Cook::Cook(string n, int skill)
    : name(n), skillLevel(skill), experienceYears(0),
    specialty(""), age(0), awards(0), isAvailable(true) {}

string Cook::getName() const { return name; }
int Cook::getSkillLevel() const { return skillLevel; }
const vector<Dish>& Cook::getDishes() const { return dishes; }

int Cook::getExperienceYears() const { return experienceYears; }
string Cook::getSpecialty() const { return specialty; }
int Cook::getAge() const { return age; }
int Cook::getAwards() const { return awards; }
bool Cook::getIsAvailable() const { return isAvailable; }

void Cook::setName(const string& newName) { name = newName; }
void Cook::setSkillLevel(int newLevel) { skillLevel = newLevel; }
void Cook::setDishes(const vector<Dish>& newDishes) { dishes = newDishes; }
void Cook::addDish(const Dish& dish) { dishes.push_back(dish); }
void Cook::setExperienceYears(int y) { experienceYears = y; }
void Cook::setSpecialty(const string& s) { specialty = s; }
void Cook::setAge(int a) { age = a; }
void Cook::setAwards(int a) { awards = a; }
void Cook::setIsAvailable(bool avail) { isAvailable = avail; }
