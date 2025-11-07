#include "Goal.h"
#include "Exception.h" 

Goal::Goal(string n, double target, string u)
    : name(n), targetValue(target), currentValue(0), unit(u), achieved(false) {}

string Goal::getName() const { return name; }
double Goal::getTarget() const { return targetValue; }
double Goal::getCurrent() const { return currentValue; }
string Goal::getUnit() const { return unit; }
bool Goal::isAchieved() const { return achieved; }

void Goal::updateProgress(double value) {
    if (value < 0) throw GoalException("Progress cannot be negative");
    currentValue += value;
    if (currentValue >= targetValue) achieved = true;
}

void Goal::setAchieved(bool val) { achieved = val; }
