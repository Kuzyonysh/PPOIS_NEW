#include "BodyMetricsManager.h"
#include <cmath>

void BodyMetricsManager::addMetrics(const BodyMetrics& metrics) {
    records.push_back(metrics);
    cout << "Body metrics for " << metrics.getDate() << " added." << endl;
}

BodyMetrics BodyMetricsManager::getLatestMetrics() const {
    if (records.empty())
        throw InvalidBodyMetricsException("No body metrics recorded yet.");
    return records.back();
}

double BodyMetricsManager::getBMI() const {
    BodyMetrics latest = getLatestMetrics();
    if (latest.getHeight() <= 0 || latest.getWeight() <= 0)
        throw InvalidHeightWeightException("Height and weight must be positive.");
    return latest.getWeight() / pow(latest.getHeight() / 100.0, 2);
}

void BodyMetricsManager::showAllRecords() const {
    cout << "Displaying all body metric records..." << endl;
}

void BodyMetricsManager::printLatestWeight() const {
    cout << "Latest weight: " << getLatestMetrics().getWeight() << " kg" << endl;
}

void BodyMetricsManager::printLatestHeight() const {
    cout << "Latest height: " << getLatestMetrics().getHeight() << " cm" << endl;
}

void BodyMetricsManager::notifyBMIStatus() const {
    double bmi = getBMI();
    if (bmi < 18.5) cout << "Your BMI is low. Consider healthy nutrition." << endl;
    else if (bmi <= 24.9) cout << "Your BMI is normal. Keep it up!" << endl;
    else cout << "Your BMI is high. Consider physical activity." << endl;
}

void BodyMetricsManager::resetRecords() {
    records.clear();
    cout << "All body metric records have been cleared." << endl;
}
