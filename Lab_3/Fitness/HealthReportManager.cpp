#include "HealthReportManager.h"

HealthReportManager::HealthReportManager(SleepManager& s, MealRecordManager& m, WaterIntake& w,
    BodyMetricsManager& b, MentalHealthManager& mh, FitnessTracker& f)
    : sleepManager(s), mealManager(m), water(w),
    bodyManager(b), mentalManager(mh), fitnessTracker(f) {}

HealthReport HealthReportManager::generateDailyReport(const string& date) {
    double sleepHours = sleepManager.getSleepHoursByDate(date);
    double sleepQuality = sleepManager.getAverageQuality();
    double calIn = mealManager.getTotalCaloriesByDate(date);
    double calOut = fitnessTracker.getTotalCaloriesBurned();
    double waterAmount = water.getAmount();
    double waterGoal = water.getDailyGoal();
    double mood = mentalManager.getAverageMood();

    BodyMetrics body = bodyManager.getLatestMetrics();
    double weight = body.getWeight();
    double bmi = bodyManager.getBMI();
    double waist = body.getWaist();
    double hips = body.getHips();

    HealthReport report(date, sleepHours, sleepQuality, calIn, calOut,
        waterAmount, waterGoal, mood, "balanced",
        weight, bmi, waist, hips);

    reports.push_back(report);
    return report;
}

vector<HealthReport> HealthReportManager::getAllReports() const { return reports; }
