#pragma once
#include "IFitnessTracker.h"
#include <string>
#include <vector>
using namespace std;

class FitnessTracker : public IFitnessTracker {
private:
    string activityType;
    string activityDate;
    double activityDuration;
    double activityCalories;

    vector<string> types;
    vector<string> dates;
    vector<double> durations;
    vector<double> calories;
    double totalCaloriesBurned = 0;

public:
    void setActivityType(const string& type) override;
    void setActivityDate(const string& date) override;
    void setActivityDuration(double duration) override;
    void setActivityCalories(double cal) override;

    void addActivity(const string& type, const string& date, double duration, double cal) override;

    string getActivityType() const override;
    string getActivityDate() const override;
    double getActivityDuration() const override;
    double getActivityCalories() const override;

    vector<string> getAllTypes() const override;
    vector<string> getAllDates() const override;
    vector<double> getAllDurations() const override;
    vector<double> getAllCalories() const override;
    double getTotalCaloriesBurned() const override;
};
