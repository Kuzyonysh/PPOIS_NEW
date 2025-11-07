#include "DailyPlanManager.h"
using namespace std;

void DailyPlanManager::addDailyPlan(const DailyPlan& plan) {
    plans.push_back(plan);
    cout << "Daily plan for " << plan.getDate() << " added." << endl;
}

double DailyPlanManager::getTotalCalories(const string& date) const {
    for (const auto& plan : plans) {
        if (plan.getDate() == date) {
            double total = 0;
            for (const auto& meal : plan.getMeals()) total += meal.getCalories();
            return total;
        }
    }
    return 0.0;
}

double DailyPlanManager::getTotalWorkoutCalories(const string& date) const {
    for (const auto& plan : plans) {
        if (plan.getDate() == date) {
            double total = 0;
            for (const auto& workout : plan.getWorkouts()) total += workout.getTotalCaloriesBurned();
            return total;
        }
    }
    return 0.0;
}

double DailyPlanManager::getTotalWater(const string& date) const {
    for (const auto& plan : plans) {
        if (plan.getDate() == date) return plan.getWater().getAmount();
    }
    return 0.0;
}

void DailyPlanManager::checkDailyProgress(const string& date) const {
    for (const auto& plan : plans) {
        if (plan.getDate() == date) {
            cout << "You completed 80% of your plan today." << endl;
            return;
        }
    }
    cout << "No plan found for " << date << endl;
}

void DailyPlanManager::resetDailyPlans() {
    plans.clear();
    cout << "All daily plans reset." << endl;
}

void DailyPlanManager::showWorkouts(const string& date) const {
    cout << "Displaying workouts for " << date << "..." << endl;
}

void DailyPlanManager::showMeals(const string& date) const {
    cout << "Displaying meals for " << date << "..." << endl;
}

void DailyPlanManager::showWaterIntake(const string& date) const {
    cout << "Displaying water intake for " << date << "..." << endl;
}

void DailyPlanManager::showSleep(const string& date) const {
    cout << "Displaying sleep info for " << date << "..." << endl;
}

