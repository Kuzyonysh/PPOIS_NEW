#include "HealthReport.h"

HealthReport::HealthReport(
    const string& d,
    double sleepH, double sleepQ,
    double calIn, double calOut,
    double water, double waterG,
    double mood, const string& emo,
    double weight, double bmiVal,
    double wst, double hp,
    const string& comment, bool improved)
    : date(d), avgSleepHours(sleepH), avgSleepQuality(sleepQ),
    totalCaloriesConsumed(calIn), totalCaloriesBurned(calOut),
    calorieBalance(calIn - calOut),
    totalWaterIntake(water), waterGoal(waterG),
    avgMoodLevel(mood), dominantEmotion(emo),
    currentWeight(weight), bmi(bmiVal), waist(wst), hips(hp),
    generalComment(comment), healthImproved(improved) {}

string HealthReport::getDate() const { return date; }
double HealthReport::getSleepHours() const { return avgSleepHours; }
double HealthReport::getSleepQuality() const { return avgSleepQuality; }
double HealthReport::getCaloriesIn() const { return totalCaloriesConsumed; }
double HealthReport::getCaloriesOut() const { return totalCaloriesBurned; }
double HealthReport::getCalorieBalance() const { return calorieBalance; }
double HealthReport::getWaterIntake() const { return totalWaterIntake; }
double HealthReport::getWaterGoal() const { return waterGoal; }
double HealthReport::getMoodLevel() const { return avgMoodLevel; }
string HealthReport::getEmotion() const { return dominantEmotion; }
double HealthReport::getWeight() const { return currentWeight; }
double HealthReport::getBMI() const { return bmi; }
double HealthReport::getWaist() const { return waist; }
double HealthReport::getHips() const { return hips; }
string HealthReport::getComment() const { return generalComment; }
bool HealthReport::isImproved() const { return healthImproved; }

void HealthReport::setComment(const string& c) { generalComment = c; }
void HealthReport::setImprovement(bool val) { healthImproved = val; }
void HealthReport::setMood(const string& emo, double lvl) { dominantEmotion = emo; avgMoodLevel = lvl; }
void HealthReport::updateCalorieBalance() { calorieBalance = totalCaloriesConsumed - totalCaloriesBurned; }
