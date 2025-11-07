#include "FitnessTracker.h"

void FitnessTracker::setActivityType(const string& type) { activityType = type; }
void FitnessTracker::setActivityDate(const string& date) { activityDate = date; }
void FitnessTracker::setActivityDuration(double duration) { activityDuration = duration; }
void FitnessTracker::setActivityCalories(double cal) { activityCalories = cal; }

void FitnessTracker::addActivity(const string& type, const string& date, double duration, double cal) {
    setActivityType(type);
    setActivityDate(date);
    setActivityDuration(duration);
    setActivityCalories(cal);

    types.push_back(type);
    dates.push_back(date);
    durations.push_back(duration);
    calories.push_back(cal);
    totalCaloriesBurned += cal;
}

string FitnessTracker::getActivityType() const { return activityType; }
string FitnessTracker::getActivityDate() const { return activityDate; }
double FitnessTracker::getActivityDuration() const { return activityDuration; }
double FitnessTracker::getActivityCalories() const { return activityCalories; }

vector<string> FitnessTracker::getAllTypes() const { return types; }
vector<string> FitnessTracker::getAllDates() const { return dates; }
vector<double> FitnessTracker::getAllDurations() const { return durations; }
vector<double> FitnessTracker::getAllCalories() const { return calories; }
double FitnessTracker::getTotalCaloriesBurned() const { return totalCaloriesBurned; }
