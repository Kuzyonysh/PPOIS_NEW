#pragma once
#include <vector>
#include "HealthReport.h"
#include "SleepManager.h"
#include "MealRecordManager.h"
#include "WaterIntake.h"
#include "BodyMetricsManager.h"
#include "MentalHealthManager.h"
#include "FitnessTracker.h"
using namespace std;

class HealthReportManager {
private:
    vector<HealthReport> reports;

    SleepManager& sleepManager;
    MealRecordManager& mealManager;
    WaterIntake& water;
    BodyMetricsManager& bodyManager;
    MentalHealthManager& mentalManager;
    FitnessTracker& fitnessTracker;

public:
    HealthReportManager() = default;

    HealthReportManager(SleepManager& s, MealRecordManager& m, WaterIntake& w,
        BodyMetricsManager& b, MentalHealthManager& mh, FitnessTracker& f);

    HealthReport generateDailyReport(const string& date);
    vector<HealthReport> getAllReports() const;
};

