#pragma once
#include <iostream>
#include "ICustomer.h"
#include "Dish.h"
using namespace std;

class MakeOrder {
public:
    virtual ~MakeOrder() = default;
    virtual void makeOrder(ICustomer& customer, const Dish& dish) const = 0;
};

class ConsoleMakeOrder : public MakeOrder {
public:
    void makeOrder(ICustomer& customer, const Dish& dish) const override;
};
