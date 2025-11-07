#include "PrinterDailyPlan.h"

PrinterDailyPlan::PrinterDailyPlan(const DailyPlanManager& m) : manager(m) {}

void PrinterDailyPlan::print(const DailyPlan& plan) const {
    cout << "Date: " << plan.getDate() << endl;

    cout << "--- Workouts ---" << endl;
    cout << plan.getWorkouts().size() << " workouts, total calories burned: "
        << manager.getTotalWorkoutCalories(plan.getDate()) << endl;

    cout << "--- Meals ---" << endl;
    double mealCalories = 0;
    for (const auto& meal : plan.getMeals()) {
        cout << meal.getMealType() << " (" << meal.getCalories() << " kcal)" << endl;
        mealCalories += meal.getCalories();
    }
    cout << "Total meal calories: " << mealCalories << endl;

    cout << "--- Water ---" << endl;
    cout << plan.getWater().getAmount() << " ml (goal: "
        << plan.getWater().getDailyGoal() << " ml)" << endl;

    cout << "--- Sleep ---" << endl;
    cout << plan.getSleep().getHours() << " hours, quality: "
        << plan.getSleep().getQuality() << "/10" << endl;
}
