#include "BodyMetrics.h"

BodyMetrics::BodyMetrics(const string& d, double w, double h, double wa, double hi)
    : date(d), weight(w), height(h), waist(wa), hips(hi) {}

string BodyMetrics::getDate() const { return date; }
double BodyMetrics::getWeight() const { return weight; }
double BodyMetrics::getHeight() const { return height; }
double BodyMetrics::getWaist() const { return waist; }
double BodyMetrics::getHips() const { return hips; }

void BodyMetrics::setDate(const string& d) { date = d; }
void BodyMetrics::setWeight(double w) { weight = w; }
void BodyMetrics::setHeight(double h) { height = h; }
void BodyMetrics::setWaist(double wa) { waist = wa; }
void BodyMetrics::setHips(double hi) { hips = hi; }
