#include "PrinterFitnessTracker.h"

void PrinterFitnessTracker::print(const IFitnessTracker& track) const {
    cout << "Type: " << track.getActivityType() << endl;
    cout << "Date: " << track.getActivityDate() << endl;
    cout << "Duration: " << track.getActivityDuration() << " min" << endl;
    cout << "Calories: " << track.getActivityCalories() << " kcal" << endl;
}
