#include "WaterIntakeManager.h"

WaterIntakeManager::WaterIntakeManager(WaterIntake& i) : intake(i) {}

void WaterIntakeManager::addWater(double portion) {
    if (portion <= 0) {
        throw InvalidWaterAmountException("Amount of water to add must be positive!");
    }
    intake.setAmount(intake.getAmount() + portion);
    cout << portion << " ml of water added. Total: " << intake.getAmount() << " ml." << endl;
}

bool WaterIntakeManager::checkNorm() const {
    return intake.getAmount() >= intake.getDailyGoal();
}

void WaterIntakeManager::printProgress() const {
    double progress = intake.getAmount() / intake.getDailyGoal() * 100.0;
    cout << "Water intake progress: " << progress << "% (" << intake.getAmount()
        << " / " << intake.getDailyGoal() << " ml)" << endl;
}

void WaterIntakeManager::remindToDrink() const {
    if (!checkNorm()) {
        double remaining = intake.getDailyGoal() - intake.getAmount();
        cout << "[Reminder] Drink " << remaining << " ml more water today!" << endl;
    }
    else {
        cout << "Congratulations! You've reached your daily water goal!" << endl;
    }
}

void WaterIntakeManager::resetAmount() {
    intake.setAmount(0);
    cout << "Water intake reset for new day." << endl;
}
