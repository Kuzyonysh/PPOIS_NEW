#pragma once
#include "IPayment.h"

class Payment : public IPayment {
private:
    double amount;
    string method;
    bool paid;

    string currency;
    string transactionId;
    string payerName;
    string recipientName;
    string paymentDate;
    string notes;
    bool isRecurring;

public:
    Payment(double a, const string& m, bool p = false);

    void pay() override;
    void refund() override;
    double getAmount() const override;
    string getMethod() const override;
    bool isPaid() const override;

    string getCurrency() const;
    string getTransactionId() const;
    string getPayerName() const;
    string getRecipientName() const;
    string getPaymentDate() const;
    string getNotes() const;
    bool getIsRecurring() const;

    void setAmount(double a);
    void setMethod(const string& m);
    void setCurrency(const string& c);
    void setTransactionId(const string& id);
    void setPayerName(const string& name);
    void setRecipientName(const string& name);
    void setPaymentDate(const string& date);
    void setNotes(const string& n);
    void setRecurring(bool r);
};
