#pragma once
#include "BodyMetrics.h"
#include "Exception.h"
#include "Printer.h"
#include <vector>
#include <iostream>
using namespace std;

class BodyMetricsManager {
private:
    vector<BodyMetrics> records;

public:
    BodyMetricsManager() = default;
    void addMetrics(const BodyMetrics& metrics);
    BodyMetrics getLatestMetrics() const;
    double getBMI() const;

    void showAllRecords() const;
    void printLatestWeight() const;
    void printLatestHeight() const;
    void notifyBMIStatus() const;
    void resetRecords();
};

