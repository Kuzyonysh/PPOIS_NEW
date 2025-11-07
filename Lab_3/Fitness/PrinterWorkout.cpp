#include "PrinterWorkout.h"

void PrinterWorkout::print(const WorkoutSession& w) const {
    cout << "Workout Summary" << endl;
    cout << "Date: " << w.getDate() << endl;
    cout << "Type: " << w.getType() << " (" << w.getIntensity() << ")" << endl;
    cout << "Duration: " << w.getDuration() << " min" << endl;
    cout << "Calories: " << w.getCalories() << " kcal" << endl;
    cout << "Distance: " << w.getDistance() << " km" << endl;
    cout << "Steps: " << w.getSteps() << endl;
    cout << "Heart Rate: " << w.getHeartRate() << " bpm" << endl;
    cout << "Trainer: " << w.getTrainerName() << endl;
    cout << "Location: " << w.getLocation() << endl;
    cout << "Completed: " << (w.isCompleted() ? "Yes" : "No") << endl;
    if (!w.getNotes().empty())
        cout << "Notes: " << w.getNotes() << endl;
}
