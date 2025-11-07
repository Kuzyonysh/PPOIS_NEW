#pragma once
#include <string>
#include <vector>
using namespace std;

class IFitnessTracker {
public:
    virtual ~IFitnessTracker() = default;

    virtual string getActivityType() const = 0;
    virtual string getActivityDate() const = 0;
    virtual double getActivityDuration() const = 0;
    virtual double getActivityCalories() const = 0;

    virtual vector<string> getAllTypes() const = 0;
    virtual vector<string> getAllDates() const = 0;
    virtual vector<double> getAllDurations() const = 0;
    virtual vector<double> getAllCalories() const = 0;
    virtual double getTotalCaloriesBurned() const = 0;

    virtual void setActivityType(const string& type) = 0;
    virtual void setActivityDate(const string& date) = 0;
    virtual void setActivityDuration(double duration) = 0;
    virtual void setActivityCalories(double cal) = 0;
    virtual void addActivity(const string& type, const string& date, double duration, double cal) = 0;
};
