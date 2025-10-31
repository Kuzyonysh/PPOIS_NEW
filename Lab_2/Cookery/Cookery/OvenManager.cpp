#include "OvenManager.h"
#include "Exceptions.h"

void OvenManager::startCooking(Oven& oven) const {
    if (oven.getTemperature() <= 0 || oven.getCookingTime() <= 0 || oven.getMode().empty()) {
        throw OvenException("Not all oven parameters are set!");
    }
    cout << "The oven started cooking in mode '" << oven.getMode()
        << "' at " << oven.getTemperature() << "°C for "
        << oven.getCookingTime() << " minutes." << endl;
}

void OvenManager::stopCooking(Oven& oven) const {
    oven.setCookingTime(0);
    cout << "Cooking is finished. The oven is off." << endl;
}

void OvenManager::openDoor(Oven& oven) const {
    oven.setDoorState(false);
    cout << "The oven door is now open." << endl;
}

void OvenManager::closeDoor(Oven& oven) const {
    oven.setDoorState(true);
    cout << "The oven door is now closed." << endl;
}

void OvenManager::clean() const {
    cout << "The oven is being cleaned. Please wait..." << endl;
    cout << "Cleaning complete!" << endl;
}

void OvenManager::preheat(Oven& oven, double targetTemp) {
    if (!oven.getPowerState()) {
        cout << "You must turn on the oven before preheating!" << endl;
        return;
    }
    oven.setTemperature(targetTemp);
    cout << "Preheating oven to " << targetTemp << "°C..." << endl;
    cout << "Oven is preheated!" << endl;
}

void OvenManager::resetSettings(Oven& oven) const {
    oven.setCookingTime(0);
    oven.setMode("");
    oven.setTemperature(0);
    cout << "Oven settings have been reset." << endl;
}

void OvenManager::testHeating(Oven& oven) const {
    cout << "Testing heating elements..." << endl;
    cout << "Temperature is stable at " << oven.getTemperature() << "°C." << endl;
    cout << "Heating test passed successfully!" << endl;
}
