#include "Oven.h"
#include <iostream>

Oven::Oven(double temp, string m, int time, string b, double p)
    : temperature(temp), mode(m), cookingTime(time), isOn(false), isDoorClosed(true),
    brand(b), power(p), color("white"), material("steel"), capacity(50),
    width(60.0), height(45.0), depth(55.0), hasTimer(true), hasLight(true) {}

double Oven::getTemperature() const { return temperature; }
string Oven::getMode() const { return mode; }
int Oven::getCookingTime() const { return cookingTime; }
bool Oven::getPowerState() const { return isOn; }
bool Oven::getDoorState() const { return isDoorClosed; }
string Oven::getBrand() const { return brand; }
double Oven::getPower() const { return power; }
string Oven::getColor() const { return color; }
string Oven::getMaterial() const { return material; }
int Oven::getCapacity() const { return capacity; }
double Oven::getWidth() const { return width; }
double Oven::getHeight() const { return height; }
double Oven::getDepth() const { return depth; }
bool Oven::hasTimerFunction() const { return hasTimer; }
bool Oven::hasLightFunction() const { return hasLight; }

void Oven::setTemperature(double t) {
    if (t >= 50 && t <= 300)
        temperature = t;
    else
        throw InvalidTemperatureException(to_string(t));
}

void Oven::setMode(string m) {
    vector<string> validModes = { "baking", "grill", "defrosting" };
    bool isValid = false;
    for (const auto& modeName : validModes) {
        if (m == modeName) {
            isValid = true;
            break;
        }
    }
    if (!isValid)
        throw InvalidModeException(m);
    mode = m;
}

void Oven::setCookingTime(int t) {
    if (t > 0)
        cookingTime = t;
    else
        throw InvalidTimeException(to_string(t));
}

void Oven::setDoorState(bool closed) { isDoorClosed = closed; }
void Oven::setPowerState(bool on) { isOn = on; }
void Oven::setColor(const string& c) { color = c; }
void Oven::setMaterial(const string& m) { material = m; }
void Oven::setCapacity(int c) { capacity = c; }
void Oven::setWidth(double w) { width = w; }
void Oven::setHeight(double h) { height = h; }
void Oven::setDepth(double d) { depth = d; }
void Oven::setTimerFunction(bool t) { hasTimer = t; }
void Oven::setLightFunction(bool l) { hasLight = l; }
