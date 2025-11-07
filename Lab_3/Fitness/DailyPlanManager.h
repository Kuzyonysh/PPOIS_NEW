#pragma once
#include <vector>
#include <iostream>
#include "DailyPlan.h"
using namespace std;

class DailyPlanManager {
private:
    vector<DailyPlan> plans;

public:
    DailyPlanManager() = default;
    void addDailyPlan(const DailyPlan& plan);
    double getTotalCalories(const string& date) const;
    double getTotalWorkoutCalories(const string& date) const;
    double getTotalWater(const string& date) const;

    void checkDailyProgress(const string& date) const;
    void resetDailyPlans();

    void showWorkouts(const string& date) const;
    void showMeals(const string& date) const;
    void showWaterIntake(const string& date) const;
    void showSleep(const string& date) const;
};
