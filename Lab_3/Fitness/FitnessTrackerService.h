#pragma once
#include "IFitnessTracker.h"
#include "IUser.h"
#include "UserManager.h"
#include "Exception.h"
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;


class FitnessTrackerService {
private:
    IFitnessTracker& tracker;
    IUser& user;
    UserManager& manager;

public:
    FitnessTrackerService() = default;
    FitnessTrackerService(IFitnessTracker& t, IUser& u, UserManager& m);

    double getAverageCaloriesBurned() const;
    double getTotalDuration() const;
    string getMostCalorieBurningActivity() const;
    double getAverageDuration() const;
    double getCaloriesPerMinute() const;
};

