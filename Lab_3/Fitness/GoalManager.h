#pragma once
#include <vector>
#include <algorithm>
#include "Goal.h"
using namespace std;

class GoalManager {
private:
    vector<Goal> goals;

public:
    GoalManager() = default;
    void addGoal(const Goal& g);
    vector<Goal> getAchievedGoals() const;
    vector<Goal> getPendingGoals() const;
    bool markGoalAchieved(const string& name);
    bool removeGoal(const string& name);
    void printAllGoals() const;
    size_t totalGoals() const;
    size_t achievedCount() const;
    size_t pendingCount() const;
};

