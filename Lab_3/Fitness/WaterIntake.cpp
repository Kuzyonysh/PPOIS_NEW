#include "WaterIntake.h"

WaterIntake::WaterIntake(const string& d, double a, double goal, const string& n)
    : date(d), amount(a), dailyGoal(goal), note(n) {}

string WaterIntake::getDate() const { return date; }
double WaterIntake::getAmount() const { return amount; }
double WaterIntake::getDailyGoal() const { return dailyGoal; }
string WaterIntake::getNote() const { return note; }

void WaterIntake::setDate(const string& newDate) { date = newDate; }
void WaterIntake::setAmount(double newAmount) { amount = newAmount; }
void WaterIntake::setDailyGoal(double goal) { dailyGoal = goal; }
void WaterIntake::setNote(const string& n) { note = n; }
