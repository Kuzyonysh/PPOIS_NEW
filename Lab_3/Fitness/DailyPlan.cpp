#include "DailyPlan.h"

DailyPlan::DailyPlan(string d, WaterIntake w, SleepRecord s)
    : date(d), water(w), sleep(s) {}

string DailyPlan::getDate() const { return date; }
void DailyPlan::setDate(const string& d) { date = d; }

vector<FitnessTracker> DailyPlan::getWorkouts() const { return workouts; }
void DailyPlan::addWorkout(const FitnessTracker& f) { workouts.push_back(f); }

vector<MealRecord> DailyPlan::getMeals() const { return meals; }
void DailyPlan::addMeal(const MealRecord& m) { meals.push_back(m); }

WaterIntake DailyPlan::getWater() const { return water; }
void DailyPlan::setWater(const WaterIntake& w) { water = w; }

SleepRecord DailyPlan::getSleep() const { return sleep; }
void DailyPlan::setSleep(const SleepRecord& s) { sleep = s; }

