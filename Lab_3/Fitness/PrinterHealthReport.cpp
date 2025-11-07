#include "PrinterHealthReport.h"

void PrinterHealthReport::print(const HealthReport& r) const {
    cout << "Health Report for " << r.getDate() << " =====" << endl;
    cout << "Sleep: " << r.getSleepHours() << "h (" << r.getSleepQuality() << "% quality)" << endl;
    cout << "Calories: " << r.getCaloriesIn() << " in / " << r.getCaloriesOut() << " out" << endl;
    cout << "Balance: " << r.getCalorieBalance() << " kcal" << endl;
    cout << "Water: " << r.getWaterIntake() << " / " << r.getWaterGoal() << " ml" << endl;
    cout << "Mood: " << r.getMoodLevel() << " (" << r.getEmotion() << ")" << endl;
    cout << "Body: " << r.getWeight() << " kg, BMI " << r.getBMI()
        << ", Waist " << r.getWaist() << " cm, Hips " << r.getHips() << " cm" << endl;
    cout << "Comment: " << r.getComment() << endl;
    cout << "Trend: " << (r.isImproved() ? "Improved" : "Needs attention") << endl;
}
