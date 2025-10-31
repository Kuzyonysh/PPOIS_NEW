#pragma once
#include "ITool.h"

class Tool : public ITool {
private:
    string name;
    string condition;
    string purpose;
    string material;
    double weight;

    string brand;
    string color;
    int durability;
    double length;
    double width;

public:
    Tool(string n, string c, string p, string m = "steel", double w = 1.0);

    string getName() const override;
    string getConditionName() const override;
    string getPurposeName() const override;
    string getMaterial() const;
    double getWeight() const;

    string getBrand() const;
    string getColor() const;
    int getDurability() const;
    double getLength() const;
    double getWidth() const;

    void setCondition(const string& c) override;
    void setMaterial(const string& m);
    void setWeight(double w);
    void setBrand(const string& b);
    void setColor(const string& c);
    void setDurability(int d);
    void setLength(double l);
    void setWidth(double w);
};

