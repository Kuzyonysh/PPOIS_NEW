#include "UserManager.h"

void UserManager::validateHeightWeight() const {
    if (user.getHeight() <= 0 || user.getWeight() <= 0) {
        throw InvalidHeightWeightException(
            "Height: " + to_string(user.getHeight()) +
            ", Weight: " + to_string(user.getWeight()));
    }
}

UserManager::UserManager(IUser& u, BodyMetricsManager& bm)
    : user(u), metricsMgr(bm)
{
    validateHeightWeight(); 
}

double UserManager::getCurrentBMI() {
    validateHeightWeight();
    return metricsMgr.getBMI();
}

double UserManager::getBMR() {
    validateHeightWeight();
    int s = (user.getGender() == "woman") ? -161 : 5;
    return 10 * user.getWeight() + 6.25 * user.getHeight() - 5 * user.getAge() + s;
}

double UserManager::getActivityMultiplier(int activityLevel) {
    return (activityLevel <= 0) ? 1.2 :
        (activityLevel < 3) ? 1.375 :
        (activityLevel < 5) ? 1.55 :
        (activityLevel < 7) ? 1.725 : 1.9;
}

double UserManager::getTDEE(int activityLevel) {
    validateHeightWeight();
    return getBMR() * getActivityMultiplier(activityLevel);
}

bool UserManager::isHealthyWeightRange() {
    validateHeightWeight();
    double bmi = getCurrentBMI();
    return (bmi >= 18.5 && bmi <= 24.9);
}

pair<double, double> UserManager::getIdealWeightRange() {
    validateHeightWeight();
    double heightMeters = user.getHeight() / 100.0;
    double minIdeal = 18.5 * pow(heightMeters, 2);
    double maxIdeal = 24.9 * pow(heightMeters, 2);
    return { minIdeal, maxIdeal };
}

void UserManager::printBMIStatus() {
    validateHeightWeight();
    double bmi = getCurrentBMI();
    if (isHealthyWeightRange())
        cout << "Your BMI is normal: " << bmi << endl;
    else
        cout << "Your BMI indicates you need attention: " << bmi << endl;
}
