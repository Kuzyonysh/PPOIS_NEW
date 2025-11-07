#pragma once
#include "INutrition.h"
#include "MealRecordManager.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class PrinterMeal : public Printer<INutrition> {
private:
    const MealRecordManager& manager;
public:
    PrinterMeal(const MealRecordManager& m);
    void print(const INutrition& meal) const override;
};

