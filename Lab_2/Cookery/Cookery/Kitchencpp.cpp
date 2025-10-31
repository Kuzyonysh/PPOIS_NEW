#include "Kitchen.h"

void Kitchen::addTool(const Tool& t) {
    if ((int)tools.size() >= capacity)
        throw runtime_error("Kitchen capacity exceeded!");
    tools.push_back(t);
}

void Kitchen::addWorkplace(const string& wp) {
    if ((int)workplace.size() >= capacity)
        throw runtime_error("Kitchen capacity exceeded!");
    workplace.push_back(wp);
}
