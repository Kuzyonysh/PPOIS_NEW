#include "SleepRecord.h"

SleepRecord::SleepRecord(const string& d, double h, int q)
    : date(d), hours(h), quality(q) {}

string SleepRecord::getDate() const { return date; }
double SleepRecord::getHours() const { return hours; }
int SleepRecord::getQuality() const { return quality; }

void SleepRecord::setDate(const string& ndate) { date = ndate; }
void SleepRecord::setHours(double nhour) { hours = nhour; }
void SleepRecord::setQuality(int q) { quality = q; }
