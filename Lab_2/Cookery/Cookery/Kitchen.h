#pragma once
#include "IKitchen.h"
#include <stdexcept>
#include <iostream>

class Kitchen : public IKitchen {
private:
    string name;
    int capacity;
    vector<Tool> tools;
    vector<string> workplace;

public:
    Kitchen(string n = "DefaultKitchen", int c = 10)
        : name(std::move(n)), capacity(c) {}

    const vector<Tool>& getTools() const override { return tools; }
    const vector<string>& getWorkplaces() const override { return workplace; }
    const string& getName() const override { return name; }
    int getCapacity() const override { return capacity; }

    void addTool(const Tool& t) override;
    void addWorkplace(const string& wp) override;

    void setName(const string& n) override { name = n; }
    void setCapacity(int c) override { capacity = c; }

    bool isReady() const override { return !workplace.empty() && !tools.empty(); }
};
