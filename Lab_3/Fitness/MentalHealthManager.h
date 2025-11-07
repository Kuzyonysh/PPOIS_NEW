#pragma once
#include <vector>
#include <string>
#include "MoodRecord.h"
#include "Exception.h"
using namespace std;

class MentalHealthManager {
private:
    vector<MoodRecord> records;

public:
    MentalHealthManager() = default;
    void addMoodRecord(const MoodRecord& record);
    double getAverageMood() const;
    double getAverageStress() const;
    MoodRecord getMoodByDate(const string& date) const;
};

