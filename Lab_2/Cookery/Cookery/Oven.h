#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Printer.h"
#include "Exceptions.h"
using namespace std;

class Oven {
private:
    double temperature;
    string mode;
    int cookingTime;
    bool isOn;
    bool isDoorClosed;
    string brand;
    double power;

    string color;
    string material;
    int capacity;
    double width;
    double height;
    double depth;
    bool hasTimer;
    bool hasLight;

public:
    Oven(double temp = 0, string m = "", int time = 0, string b = "Generic", double p = 2.0);

    double getTemperature() const;
    string getMode() const;
    int getCookingTime() const;
    bool getPowerState() const;
    bool getDoorState() const;
    string getBrand() const;
    double getPower() const;
    string getColor() const;
    string getMaterial() const;
    int getCapacity() const;
    double getWidth() const;
    double getHeight() const;
    double getDepth() const;
    bool hasTimerFunction() const;
    bool hasLightFunction() const;

    void setTemperature(double t);
    void setMode(string m);
    void setCookingTime(int t);
    void setDoorState(bool closed);
    void setPowerState(bool on);
    void setColor(const string& c);
    void setMaterial(const string& m);
    void setCapacity(int c);
    void setWidth(double w);
    void setHeight(double h);
    void setDepth(double d);
    void setTimerFunction(bool t);
    void setLightFunction(bool l);
};
