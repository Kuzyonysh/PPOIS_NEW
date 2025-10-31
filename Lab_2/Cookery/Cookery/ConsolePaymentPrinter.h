#pragma once
#include "Printer.h"
#include "IPayment.h"
#include <iostream>
using namespace std;

class ConsolePaymentPrinter : public Printer<IPayment> {
public:
    void print(const IPayment& payment) const override;
    void showPaymentInfo(const IPayment& payment) const;
};

