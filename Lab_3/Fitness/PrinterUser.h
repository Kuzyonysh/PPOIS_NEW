#pragma once
#include "IUser.h"
#include "Printer.h"
#include <iostream>
using namespace std;

class PrinterUser : public Printer<IUser> {
public:
    void print(const IUser& user) const override;
};
