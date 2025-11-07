#pragma once
#include "Printer.h"
#include "Membership.h"
#include <iostream>
using namespace std;

class PrinterMembership : public Printer<Membership> {
public:
    void print(const Membership& m) const override;
};
