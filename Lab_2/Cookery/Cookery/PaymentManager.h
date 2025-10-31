#pragma once
#include "IPayment.h"
#include <iostream>
using namespace std;

class PaymentManager {
public:
    void makePayment(IPayment& payment) const;
    void issueRefund(IPayment& payment) const;
};
#pragma once
