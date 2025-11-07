#pragma once
#include "Printer.h"
#include "MoodRecord.h"
#include "MentalHealthManager.h"
#include <iostream>
using namespace std;

class PrinterMentalHealth : public Printer<MoodRecord> {
private:
    const MentalHealthManager& manager;

public:
    PrinterMentalHealth(const MentalHealthManager& m);
    void print(const MoodRecord& record) const override;
};

