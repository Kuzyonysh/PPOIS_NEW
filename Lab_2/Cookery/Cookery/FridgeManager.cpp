#include "FridgeManager.h"

FridgeManager::FridgeManager(ITemperatureSensor& s, int maxSafe)
    : sensor(s), maxSafeTemp(maxSafe) {}

void FridgeManager::turnOnOff(IFridge& fridge) const {
    if (fridge.getState() == "Off") {
        fridge.setState("On");
        fridge.setTemperature(4);
        sensor.setCurrentTemperature(fridge.getTemperature());
        cout << "Fridge is now ON. Temperature set to "
            << fridge.getTemperature() << " °C\n";
    }
    else {
        fridge.setState("Off");
        cout << "Fridge is now OFF. Ingredients may spoil!\n";
    }
}

void FridgeManager::setTemperature(IFridge& fridge, double t) const {
    fridge.setTemperature(t);
    sensor.setCurrentTemperature(fridge.getTemperature());
    cout << "Temperature is set to " << fridge.getTemperature() << " °C\n";
}

void FridgeManager::addIngredient(IFridge& fridge, const Ingredient& i) const {
    if (fridge.getState() == "Off") {
        throw NotEnoughTemperatureException("Fridge is turned off");
    }
    if (sensor.getCurrentTemperature() > maxSafeTemp) {
        throw NotEnoughTemperatureException(
            "Current temperature (" + to_string(sensor.getCurrentTemperature()) + " °C) is too high");
    }
    if (fridge.getInventory().size() >= fridge.getMaxCapacity()) {
        throw FridgeOverflowException(i.getName());
    }

    fridge.getInventory().addIngredient(i);
    cout << i.getName() << " added to fridge.\n";
}
