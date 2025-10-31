#pragma once
#include <string>
using namespace std;


class ITool {
public:
    virtual ~ITool() = default;
    virtual string getName() const = 0;
    virtual string getConditionName() const = 0;
    virtual string getPurposeName() const = 0;
    virtual void setCondition(const string& c) = 0;
};


