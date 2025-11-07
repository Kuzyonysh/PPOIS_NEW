#include "MembershipManager.h"
#include "Exception.h"  

void MembershipManager::addMembership(const Membership& m) {
    memberships.push_back(m);
}

int MembershipManager::getActiveCount() const {
    int count = 0;
    for (const auto& m : memberships)
        if (m.getActive()) count++;
    return count;
}

Membership& MembershipManager::findByType(const string& type) {
    for (auto& m : memberships)
        if (m.getType() == type)
            return m;
    throw MembershipException("Membership with type '" + type + "' not found.");
}

vector<Membership> MembershipManager::getAll() const { return memberships; }
