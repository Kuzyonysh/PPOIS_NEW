#include "User.h"

User::User(string n, int a, double w, double h, string g, int act)
    : name(n), age(a), weight(w), height(h), gender(g), activity(act) {}

string User::getName() const { return name; }
int User::getAge() const { return age; }
double User::getWeight() const { return weight; }
double User::getHeight() const { return height; }
string User::getGender() const { return gender; }
int User::getActivity() const { return activity; }

void User::setName(string n) { name = n; }
void User::setAge(int a) { age = a; }
void User::setWeight(double w) { weight = w; }
void User::setHeight(double h) { height = h; }
void User::setGender(string g) { gender = g; }
void User::setActivity(int act) { activity = act; }
