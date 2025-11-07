#include "Membership.h"

Membership::Membership(string name, string t, double p, string start, string end, bool paid)
    : memberName(name), type(t), price(p), startDate(start), endDate(end),
    isActive(true), isPaid(paid) {}

void Membership::deactivate() { isActive = false; }
void Membership::renew(string newEndDate) { endDate = newEndDate; isActive = true; }
void Membership::markPaid() { isPaid = true; }

string Membership::getType() const { return type; }
string Membership::getStartDate() const { return startDate; }
string Membership::getEndDate() const { return endDate; }
bool Membership::getActive() const { return isActive; }
bool Membership::getPaid() const { return isPaid; }
