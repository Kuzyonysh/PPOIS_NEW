#include "PanManager.h"

void PanHeatingManager::heatUp(IPan& pan, double targetTemp) const {
    if (targetTemp > 400)
        throw InvalidTemperatureException("Temperature too high for pan!");
    pan.setTemperature(targetTemp);
    pan.setState("use");
    cout << "Pan heated up to " << targetTemp << "°C.\n";
}

void PanHeatingManager::coolDown(IPan& pan) const {
    pan.setTemperature(25);
    cout << "Pan has cooled down to room temperature.\n";
}

void PanHeatingManager::checkReady(const IPan& pan) const {
    if (pan.getTemperature() > 180)
        cout << "Pan is hot and ready for frying!\n";
    else
        cout << "Pan is still warming up.\n";
}

void PanCareManager::clean(IPan& pan) const {
    pan.setState("clean");
    pan.setTemperature(25);
    cout << "The pan has been cleaned and cooled down.\n";
}

void PanCareManager::inspect(const Pan& pan) const {
    cout << "Inspecting " << pan.getBrand() << " pan (" << pan.getMaterial()
        << ", " << pan.getDiameter() << " cm)...\n";
    cout << "State: " << pan.getState() << ", Temp: "
        << pan.getTemperature() << "°C, "
        << (pan.getHasLid() ? "has lid" : "no lid") << ".\n";
}

void PanStorageManager::cover(Pan& pan) const {
    if (!pan.getHasLid())
        cout << "This pan doesn’t have a lid.\n";
    else
        cout << "Pan is now covered with a lid.\n";
}

void PanStorageManager::replaceLid(Pan& pan, bool newLid) const {
    pan.setHasLid(newLid);
    cout << (newLid ? "New lid has been placed on the pan.\n"
        : "The lid has been removed.\n");
}

void PanStorageManager::store(const Pan& pan) const {
    if (pan.getState() == "clean")
        cout << "Pan stored in cabinet.\n";
    else
        cout << "Please clean the pan before storing!\n";
}
