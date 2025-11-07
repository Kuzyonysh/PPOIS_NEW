#pragma once
#include <string>
using namespace std;

class HealthReport {
private:
    string date;

    double avgSleepHours;
    double avgSleepQuality;

    double totalCaloriesConsumed;
    double totalCaloriesBurned;
    double calorieBalance;

    double totalWaterIntake;
    double waterGoal;

    double avgMoodLevel;
    string dominantEmotion;

    double currentWeight;
    double bmi;
    double waist;
    double hips;

    string generalComment;
    bool healthImproved;

public:
    HealthReport(
        const string& d,
        double sleepH = 0, double sleepQ = 0,
        double calIn = 0, double calOut = 0,
        double water = 0, double waterG = 2000,
        double mood = 0, const string& emo = "neutral",
        double weight = 0, double bmiVal = 0,
        double wst = 0, double hp = 0,
        const string& comment = "", bool improved = false);

    string getDate() const;
    double getSleepHours() const;
    double getSleepQuality() const;
    double getCaloriesIn() const;
    double getCaloriesOut() const;
    double getCalorieBalance() const;
    double getWaterIntake() const;
    double getWaterGoal() const;
    double getMoodLevel() const;
    string getEmotion() const;
    double getWeight() const;
    double getBMI() const;
    double getWaist() const;
    double getHips() const;
    string getComment() const;
    bool isImproved() const;

    void setComment(const string& c);
    void setImprovement(bool val);
    void setMood(const string& emo, double lvl);
    void updateCalorieBalance();
};
