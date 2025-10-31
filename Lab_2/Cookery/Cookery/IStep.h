#pragma once
#include <string>
using namespace std;

class IStep {
public:
    virtual ~IStep() = default;
    virtual string getAction() const = 0;
    virtual int getTime() const = 0;
};
