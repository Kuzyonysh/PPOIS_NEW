#include "MealRecordManager.h"

void MealRecordManager::addMealRecord(const MealRecord& record) {
    records.push_back(record);
}

bool MealRecordManager::removeMealRecord(const string& mealType) {
    auto it = remove_if(records.begin(), records.end(),
        [&](const MealRecord& r) { return r.getMealType() == mealType; });

    if (it != records.end()) {
        records.erase(it, records.end());
        return true;
    }
    return false;
}

vector<MealRecord> MealRecordManager::findByDate(const string& date) const {
    vector<MealRecord> result;
    for (const auto& r : records)
        if (r.getData() == date)
            result.push_back(r);
    return result;
}

double MealRecordManager::getTotalCaloriesByDate(const string& date) const {
    double total = 0.0;
    for (const auto& r : records)
        if (r.getData() == date)
            total += r.getCalories();
    return total;
}

vector<MealRecord> MealRecordManager::getAllRecords() const {
    return records;
}

void MealRecordManager::MealSkipped(const string& mealType) const {
    cout << "You skipped " << mealType << " today." << endl;
}

void MealRecordManager::MealPlanned(const string& mealType) const {
    cout << "Meal " << mealType << " has been planned for today." << endl;
}

void MealRecordManager::MealConsumed(const string& mealType) const {
    cout << "You have consumed your " << mealType << "." << endl;
}

void MealRecordManager::CaloriesGoalReached(double calories) const {
    cout << "You have reached your daily calorie goal: " << calories << " kcal." << endl;
}
