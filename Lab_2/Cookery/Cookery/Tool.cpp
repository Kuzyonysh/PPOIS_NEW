#include "Tool.h"
#include <iostream>

Tool::Tool(string n, string c, string p, string m, double w)
    : name(n), condition(c), purpose(p), material(m), weight(w),
    brand("Generic"), color("None"), durability(100), length(10.0), width(5.0) {}

string Tool::getName() const { return name; }
string Tool::getConditionName() const { return condition; }
string Tool::getPurposeName() const { return purpose; }
string Tool::getMaterial() const { return material; }
double Tool::getWeight() const { return weight; }

string Tool::getBrand() const { return brand; }
string Tool::getColor() const { return color; }
int Tool::getDurability() const { return durability; }
double Tool::getLength() const { return length; }
double Tool::getWidth() const { return width; }

void Tool::setCondition(const string& c) { condition = c; }
void Tool::setMaterial(const string& m) { material = m; }
void Tool::setWeight(double w) { weight = w; }
void Tool::setBrand(const string& b) { brand = b; }
void Tool::setColor(const string& c) { color = c; }
void Tool::setDurability(int d) { durability = d; }
void Tool::setLength(double l) { length = l; }
void Tool::setWidth(double w) { width = w; }
