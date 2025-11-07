#pragma once
#include <string>
using namespace std;

class SleepRecord {
private:
    string date;
    double hours;
    int quality;

public:
    SleepRecord(const string& d, double h, int q);

    string getDate() const;
    double getHours() const;
    int getQuality() const;

    void setDate(const string& ndate);
    void setHours(double nhour);
    void setQuality(int q);
};

