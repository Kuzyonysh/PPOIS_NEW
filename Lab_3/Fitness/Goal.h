#pragma once
#include <string>
using namespace std;

class Goal {
private:
    string name;
    double targetValue;
    double currentValue;
    string unit;
    bool achieved;

public:
    Goal(string n, double target, string u);

    string getName() const;
    double getTarget() const;
    double getCurrent() const;
    string getUnit() const;
    bool isAchieved() const;

    void updateProgress(double value);
    void setAchieved(bool val);
};
