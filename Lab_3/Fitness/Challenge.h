#pragma once
#include <string>
using namespace std;

class Challenge {
private:
    string name;
    string description;
    double target;
    double progress;
    string startDate;
    string endDate;
    bool completed;

public:
    Challenge(string n, string desc, double tgt, string start, string end);

    void updateProgress(double value);

    bool isCompleted() const;
    string getName() const;
    string getDescription() const;
    double getProgress() const;
    double getTarget() const;
};
