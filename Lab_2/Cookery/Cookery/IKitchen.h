#pragma once
#include <string>
#include <vector>
#include "Tool.h"
using namespace std;

class IKitchen {
public:
    virtual ~IKitchen() = default;

    virtual const vector<Tool>& getTools() const = 0;
    virtual const vector<string>& getWorkplaces() const = 0;
    virtual const string& getName() const = 0;
    virtual int getCapacity() const = 0;

    virtual void addTool(const Tool& t) = 0;
    virtual void addWorkplace(const string& name) = 0;
    virtual void setName(const string& n) = 0;
    virtual void setCapacity(int c) = 0;

    virtual bool isReady() const = 0;
};

