#include "Step.h"

Step::Step(string a, int t) : action(a), time(t) {}
string Step::getAction() const { return action; }
int Step::getTime() const { return time; }
