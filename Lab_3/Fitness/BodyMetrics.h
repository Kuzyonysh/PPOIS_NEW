#pragma once
#include <string>
using namespace std;

class BodyMetrics {
private:
    string date;
    double weight;
    double height;
    double waist;
    double hips;

public:
    BodyMetrics(const string& d, double w, double h, double wa, double hi);
    string getDate() const;
    double getWeight() const;
    double getHeight() const;
    double getWaist() const;
    double getHips() const;

    void setDate(const string& d);
    void setWeight(double w);
    void setHeight(double h);
    void setWaist(double wa);
    void setHips(double hi);
};
