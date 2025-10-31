#pragma once
#include "IPan.h"
#include "Exceptions.h"
#include <iostream>

class Pan : public IPan {
private:
    string material;
    double diameter;
    string state;
    double depth;
    bool hasLid;
    double temperature;
    double weight;
    string brand;

public:
    Pan(string m = "steel", double d = 20, string s = "clean", double dep = 5.0,
        bool lid = true, double t = 25.0, double w = 1.2, string b = "Generic")
        : material(m), diameter(d), state(s), depth(dep),
        hasLid(lid), temperature(t), weight(w), brand(b) {}

    string getMaterial() const { return material; }
    double getDiameter() const { return diameter; }
    string getState() const override { return state; }
    double getDepth() const { return depth; }
    bool getHasLid() const { return hasLid; }
    double getTemperature() const override { return temperature; }
    double getWeight() const { return weight; }
    string getBrand() const { return brand; }

    void setMaterial(const string& m) { material = m; }
    void setDiameter(double d);
    void setState(const string& s) override { state = s; }
    void setDepth(double dep) { depth = dep; }
    void setHasLid(bool lid) { hasLid = lid; }
    void setTemperature(double t) override;
    void setWeight(double w) { weight = w; }
    void setBrand(const string& b) { brand = b; }
};

