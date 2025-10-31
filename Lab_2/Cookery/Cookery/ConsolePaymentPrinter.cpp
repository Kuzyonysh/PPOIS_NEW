#include "ConsolePaymentPrinter.h"

void ConsolePaymentPrinter::print(const IPayment& payment) const {
    cout << "Payment information:" << endl;
    cout << "Amount: " << payment.getAmount() << " BYN" << endl;
    cout << "Method: " << payment.getMethod() << endl;
    cout << "Status: " << (payment.isPaid() ? "Paid" : "Not paid") << endl;
}

void ConsolePaymentPrinter::showPaymentInfo(const IPayment& payment) const {
    print(payment);
}
