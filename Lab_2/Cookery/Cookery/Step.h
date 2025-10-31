#pragma once
#include "IStep.h"
#include <string>
using namespace std;

class Step : public IStep {
private:
    string action;
    int time;
public:
    Step(string a, int t);
    string getAction() const override;
    int getTime() const override;
};
