#include "FitnessTrackerService.h"
#include "Exception.h"
FitnessTrackerService::FitnessTrackerService(IFitnessTracker& t, IUser& u, UserManager& m)
    : tracker(t), user(u), manager(m) {}

double FitnessTrackerService::getAverageCaloriesBurned() const {
    auto allCalories = tracker.getAllCalories();
    if (allCalories.empty()) return 0.0;
    double sum = 0;
    for (double c : allCalories) sum += c;
    return sum / allCalories.size();
}

double FitnessTrackerService::getTotalDuration() const {
    auto durations = tracker.getAllDurations();
    double total = 0;
    for (double d : durations) total += d;
    return total;
}

string FitnessTrackerService::getMostCalorieBurningActivity() const {
    auto types = tracker.getAllTypes();
    auto calories = tracker.getAllCalories();

    if (types.empty() || calories.empty()) {
        throw NoActivityDataException();
    }

    double maxCal = calories[0];
    string maxType = types[0];
    for (size_t i = 1; i < calories.size(); ++i) {
        if (calories[i] > maxCal) {
            maxCal = calories[i];
            maxType = types[i];
        }
    }
    return maxType + " (" + to_string(maxCal) + " kcal)";
}

double FitnessTrackerService::getAverageDuration() const {
    auto durations = tracker.getAllDurations();
    if (durations.empty()) return 0.0;
    double sum = 0;
    for (double d : durations) sum += d;
    return sum / durations.size();
}

double FitnessTrackerService::getCaloriesPerMinute() const {
    double totalCalories = tracker.getTotalCaloriesBurned();
    double totalMinutes = getTotalDuration();
    if (totalMinutes == 0) return 0.0;
    return totalCalories / totalMinutes;
}
