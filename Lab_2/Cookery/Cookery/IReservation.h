#pragma once
#include <string>
#include "Customer.h"
using namespace std;

class IReservation {
public:
    virtual ~IReservation() = default;
    virtual Customer getCustomer() const = 0;
    virtual string getDate() const = 0;
    virtual int getTableNumber() const = 0;
    virtual bool isConfirmed() const = 0;
    virtual void setConfirmed(bool c) = 0;
};
