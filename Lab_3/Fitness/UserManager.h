#pragma once
#include "IUser.h"
#include "BodyMetricsManager.h"
#include "Exception.h"
#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

class UserManager {
private:
    IUser& user;
    BodyMetricsManager& metricsMgr;

    void validateHeightWeight() const;

public:
    UserManager() = default;
    UserManager(IUser& u, BodyMetricsManager& bm);

    double getCurrentBMI();
    double getBMR();
    double getActivityMultiplier(int activityLevel);
    double getTDEE(int activityLevel);
    bool isHealthyWeightRange();
    pair<double, double> getIdealWeightRange();
    void printBMIStatus();
};
