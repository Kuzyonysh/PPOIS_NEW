#include "GoalManager.h"
#include <iostream>
using namespace std;

void GoalManager::addGoal(const Goal& g) { goals.push_back(g); }

vector<Goal> GoalManager::getAchievedGoals() const {
    vector<Goal> result;
    for (const auto& g : goals)
        if (g.isAchieved()) result.push_back(g);
    return result;
}

vector<Goal> GoalManager::getPendingGoals() const {
    vector<Goal> result;
    for (const auto& g : goals)
        if (!g.isAchieved()) result.push_back(g);
    return result;
}

bool GoalManager::markGoalAchieved(const string& name) {
    for (auto& g : goals) {
        if (g.getName() == name) {
            g.setAchieved(true);
            return true;
        }
    }
    return false;
}

bool GoalManager::removeGoal(const string& name) {
    auto it = remove_if(goals.begin(), goals.end(),
        [&](const Goal& g) { return g.getName() == name; });
    if (it != goals.end()) {
        goals.erase(it, goals.end());
        return true;
    }
    return false;
}

void GoalManager::printAllGoals() const {
    for (const auto& g : goals) {
        cout << g.getName() << ": " << g.getCurrent() << "/" << g.getTarget()
            << " " << g.getUnit() << (g.isAchieved() ? " (achieved)" : " (pending)") << endl;
    }
}

size_t GoalManager::totalGoals() const { return goals.size(); }
size_t GoalManager::achievedCount() const { return getAchievedGoals().size(); }
size_t GoalManager::pendingCount() const { return getPendingGoals().size(); }
