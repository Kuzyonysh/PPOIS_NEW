#pragma once
#include "Printer.h"
#include "Menu.h"
#include <iostream>
using namespace std;

class ConsoleMenuPrinter : public Printer<Menu> {
public:
    void print(const Menu& menu) const override;
};
