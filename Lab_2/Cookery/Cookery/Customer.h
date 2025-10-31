#pragma once
#include "ICustomer.h"

class Customer : public ICustomer {
private:
    string name;
    string preferences;
    vector<Dish> orders;
    string email;
    string phone;
    int loyaltyPoints;
    bool vipStatus;

public:
    Customer(const string& n = "Unknown", const string& p = "None",
        const string& e = "", const string& ph = "", int points = 0, bool vip = false);

    string getName() const override;
    const vector<Dish>& getOrders() const override;
    string getPreferences() const override;
    string getEmail() const override;
    string getPhone() const override;
    int getLoyaltyPoints() const override;
    bool isVIP() const override;

    void addOrder(const Dish& d) override;
    void setPreference(const string& pref) override;
    void setEmail(const string& e) override;
    void setPhone(const string& ph) override;
    void addLoyaltyPoints(int points) override;
    void setVIP(bool vip) override;
};
