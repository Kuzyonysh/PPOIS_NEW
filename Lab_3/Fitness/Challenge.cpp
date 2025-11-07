#include "Challenge.h"

Challenge::Challenge(string n, string desc, double tgt, string start, string end)
    : name(n), description(desc), target(tgt), progress(0),
    startDate(start), endDate(end), completed(false) {}

void Challenge::updateProgress(double value) {
    progress += value;
    if (progress >= target) completed = true;
}

bool Challenge::isCompleted() const { return completed; }
string Challenge::getName() const { return name; }
string Challenge::getDescription() const { return description; }
double Challenge::getProgress() const { return progress; }
double Challenge::getTarget() const { return target; }
