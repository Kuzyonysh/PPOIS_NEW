#pragma once
#include <string>
#include <vector>
#include "FitnessTracker.h"
#include "MealRecord.h"
#include "WaterIntake.h"
#include "SleepRecord.h"
using namespace std;

class DailyPlan {
private:
    string date;
    vector<FitnessTracker> workouts;
    vector<MealRecord> meals;
    WaterIntake water;
    SleepRecord sleep;

public:
    DailyPlan(string d, WaterIntake w, SleepRecord s);

    string getDate() const;
    void setDate(const string& d);

    vector<FitnessTracker> getWorkouts() const;
    void addWorkout(const FitnessTracker& f);

    vector<MealRecord> getMeals() const;
    void addMeal(const MealRecord& m);

    WaterIntake getWater() const;
    void setWater(const WaterIntake& w);

    SleepRecord getSleep() const;
    void setSleep(const SleepRecord& s);
};
