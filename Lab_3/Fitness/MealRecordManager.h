#pragma once
#include "MealRecord.h"
#include <vector>
#include <iostream>
using namespace std;

class MealRecordManager {
private:
    vector<MealRecord> records;

public:
    MealRecordManager() = default;
    void addMealRecord(const MealRecord& record);
    bool removeMealRecord(const string& mealType);

    vector<MealRecord> findByDate(const string& date) const;
    double getTotalCaloriesByDate(const string& date) const;
    vector<MealRecord> getAllRecords() const;

    void MealSkipped(const string& mealType) const;
    void MealPlanned(const string& mealType) const;
    void MealConsumed(const string& mealType) const;
    void CaloriesGoalReached(double calories) const;
};

