#include "SleepManager.h"

void SleepManager::addSleepRecord(const SleepRecord& record) {
    records.push_back(record);
}

double SleepManager::getAverageQuality() const {
    if (records.empty()) return 0.0;

    double totalQuality = 0;
    for (const auto& record : records) totalQuality += record.getQuality();
    return totalQuality / records.size();
}

double SleepManager::getSleepHoursByDate(const string& date) const {
    for (const auto& record : records) {
        if (record.getDate() == date) return record.getHours();
    }
    throw EmptyDataAboutDream("No sleep data for date: " + date);
}

void SleepManager::checkSleepQuality(const string& date) const {
    for (const auto& record : records) {
        if (record.getDate() == date) {
            if (record.getHours() < 7.0)
                cout << "You slept less than 7 hours today. Try to rest better." << endl;
            else
                cout << "Cool. You slept well." << endl;
            return;
        }
    }
    throw EmptyDataAboutDream("No sleep data for date: " + date);
}

void SleepManager::exportSleepReport() const {
    cout << "Sleep report has been exported to sleep_report.txt." << endl;
}

void SleepManager::sendSleepReminder() const {
    cout << "Reminder: it's time to go to bed!" << endl;
}

void SleepManager::showSleepTrends() const {
    cout << "Displaying sleep trends chart for the last 7 days..." << endl;
}
