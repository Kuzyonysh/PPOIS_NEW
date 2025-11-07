#pragma once
#include <string>
using namespace std;

class WaterIntake {
private:
    string date;
    double amount;
    double dailyGoal;
    string note;

public:
    WaterIntake(const string& d, double a, double goal = 2000, const string& n = "");

    string getDate() const;
    double getAmount() const;
    double getDailyGoal() const;
    string getNote() const;

    void setDate(const string& newDate);
    void setAmount(double newAmount);
    void setDailyGoal(double goal);
    void setNote(const string& n);
};

