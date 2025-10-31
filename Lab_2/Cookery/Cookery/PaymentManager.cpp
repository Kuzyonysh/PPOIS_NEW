#include "PaymentManager.h"

void PaymentManager::makePayment(IPayment& payment) const {
    if (payment.isPaid()) {
        cout << "Already paid!" << endl;
    }
    else {
        payment.pay();
        cout << "Payment was successful, amount: "
            << payment.getAmount() << " BYN, method: " << payment.getMethod() << endl;
    }
}

void PaymentManager::issueRefund(IPayment& payment) const {
    if (!payment.isPaid()) {
        cout << "Payment is not made yet!" << endl;
    }
    else {
        payment.refund();
        cout << "Refund is issued." << endl;
    }
}
