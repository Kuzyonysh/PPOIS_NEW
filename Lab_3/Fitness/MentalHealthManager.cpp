#include "MentalHealthManager.h"

void MentalHealthManager::addMoodRecord(const MoodRecord& record) {
    records.push_back(record);
}

double MentalHealthManager::getAverageMood() const {
    if (records.empty()) return 0;
    double sum = 0;
    for (const auto& r : records) sum += r.getMood();
    return sum / records.size();
}

double MentalHealthManager::getAverageStress() const {
    if (records.empty()) return 0;
    double sum = 0;
    for (const auto& r : records) sum += r.getStressLevel();
    return sum / records.size();
}

MoodRecord MentalHealthManager::getMoodByDate(const string& date) const {
    for (const auto& r : records)
        if (r.getDate() == date) return r;
    throw MentalHealthException("No mood record for date: " + date);
}
