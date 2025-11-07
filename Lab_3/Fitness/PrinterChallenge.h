#pragma once
#include "Printer.h"
#include "Challenge.h"
#include <iostream>
using namespace std;

class PrinterChallenge : public Printer<Challenge> {
public:
    void print(const Challenge& c) const override;
};

