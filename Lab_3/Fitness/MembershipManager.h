#pragma once
#include <vector>
#include "Membership.h"
using namespace std;

class MembershipManager {
private:
    vector<Membership> memberships;

public:
    MembershipManager() = default;
    void addMembership(const Membership& m);
    int getActiveCount() const;
    Membership& findByType(const string& type);
    vector<Membership> getAll() const;
};

