#pragma once
#include <iostream>
#include <vector>
#include "DeliveryCalculator.h"

template<typename T>
class Printer {
public:
    virtual ~Printer() = default;
    virtual void print(const T& item) const = 0;
};

class ConsoleDeliveryPrinter : public Printer<IDelivery> {
private:
    DeliveryCalculator& calculator;

public:
    explicit ConsoleDeliveryPrinter(DeliveryCalculator& cal);
    void print(const IDelivery& d) const override;
    void printAll(const vector<IDelivery*>& deliveries) const;
};
