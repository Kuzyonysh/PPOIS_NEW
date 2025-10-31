#pragma once
#include "IReservation.h"

class Reservation : public IReservation {
private:
    Customer customer;
    string date;
    int tableNumber;
    bool confirmed;
    string specialRequest;
    int numberOfGuests;

    string occasion;
    string notes;
    double depositAmount;
    string contactPhone;
    string email;
    bool vip;

public:
    Reservation(const Customer& c, const string& d, int t, int guests = 1, const string& request = "");

    Customer getCustomer() const override;
    string getDate() const override;
    int getTableNumber() const override;
    bool isConfirmed() const override;
    void setConfirmed(bool c) override;

    void setSpecialRequest(const string& req);
    void setNumberOfGuests(int n);
    string getSpecialRequest() const;
    int getNumberOfGuests() const;

    void setOccasion(const string& o);
    void setNotes(const string& n);
    void setDepositAmount(double d);
    void setContactPhone(const string& p);
    void setEmail(const string& e);
    void setVIP(bool v);

    string getOccasion() const;
    string getNotes() const;
    double getDepositAmount() const;
    string getContactPhone() const;
    string getEmail() const;
    bool isVIP() const;
};

