#pragma once
#include <string>
using namespace std;

class IPayment {
public:
    virtual ~IPayment() = default;
    virtual void pay() = 0;
    virtual void refund() = 0;
    virtual double getAmount() const = 0;
    virtual string getMethod() const = 0;
    virtual bool isPaid() const = 0;
};
