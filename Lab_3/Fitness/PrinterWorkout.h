#pragma once
#include "Printer.h"
#include "WorkoutSession.h"
#include <iostream>
using namespace std;

class PrinterWorkout : public Printer<WorkoutSession> {
public:
    void print(const WorkoutSession& w) const override;
};

