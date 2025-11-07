#include "Equipment.h"

Equipment::Equipment(const string& n, const string& t, bool avail)
    : name(n), type(t), isAvailable(avail) {}

void Equipment::setAvailability(bool avail) { isAvailable = avail; }

string Equipment::getName() const { return name; }
string Equipment::getType() const { return type; }
bool Equipment::getAvailability() const { return isAvailable; }
