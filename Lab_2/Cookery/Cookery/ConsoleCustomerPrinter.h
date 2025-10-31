#pragma once
#include <iostream>
#include "Printer.h"
#include "ICustomer.h"
using namespace std;

class ConsoleCustomerPrinter : public Printer<ICustomer> {
public:
    void print(const ICustomer& customer) const override;
};
