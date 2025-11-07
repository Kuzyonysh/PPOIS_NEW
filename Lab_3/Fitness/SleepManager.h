#pragma once
#include "SleepRecord.h"
#include "Exception.h"
#include "Printer.h"
#include <vector>
#include <iostream>
using namespace std;

class SleepManager {
private:
    vector<SleepRecord> records;

public:
    SleepManager() = default;
    void addSleepRecord(const SleepRecord& record);
    double getAverageQuality() const;
    double getSleepHoursByDate(const string& date) const;
    void checkSleepQuality(const string& date) const;
    void exportSleepReport() const;
    void sendSleepReminder() const;
    void showSleepTrends() const;
};
