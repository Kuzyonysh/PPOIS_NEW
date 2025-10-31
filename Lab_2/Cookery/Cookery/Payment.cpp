#include "Payment.h"

Payment::Payment(double a, const string& m, bool p)
    : amount(a), method(m), paid(p),
    currency("BYN"), transactionId(""), payerName(""), recipientName(""),
    paymentDate(""), notes(""), isRecurring(false) {}

void Payment::pay() {
    if (!paid) paid = true;
}

void Payment::refund() {
    if (paid) paid = false;
}

double Payment::getAmount() const { return amount; }
string Payment::getMethod() const { return method; }
bool Payment::isPaid() const { return paid; }

string Payment::getCurrency() const { return currency; }
string Payment::getTransactionId() const { return transactionId; }
string Payment::getPayerName() const { return payerName; }
string Payment::getRecipientName() const { return recipientName; }
string Payment::getPaymentDate() const { return paymentDate; }
string Payment::getNotes() const { return notes; }
bool Payment::getIsRecurring() const { return isRecurring; }

void Payment::setAmount(double a) { amount = a; }
void Payment::setMethod(const string& m) { method = m; }
void Payment::setCurrency(const string& c) { currency = c; }
void Payment::setTransactionId(const string& id) { transactionId = id; }
void Payment::setPayerName(const string& name) { payerName = name; }
void Payment::setRecipientName(const string& name) { recipientName = name; }
void Payment::setPaymentDate(const string& date) { paymentDate = date; }
void Payment::setNotes(const string& n) { notes = n; }
void Payment::setRecurring(bool r) { isRecurring = r; }
