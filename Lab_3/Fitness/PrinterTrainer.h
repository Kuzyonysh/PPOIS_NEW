#pragma once
#include "Printer.h"
#include "ITrainer.h"
#include <iostream>
using namespace std;

class PrinterTrainer : public Printer<ITrainer> {
public:
    void print(const ITrainer& t) const override;
};
