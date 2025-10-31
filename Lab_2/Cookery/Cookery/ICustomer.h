#pragma once
#include <string>
#include <vector>
#include "Dish.h"
using namespace std;

class ICustomer {
public:
    virtual ~ICustomer() = default;

    virtual string getName() const = 0;
    virtual const vector<Dish>& getOrders() const = 0;
    virtual string getPreferences() const = 0;
    virtual string getEmail() const = 0;
    virtual string getPhone() const = 0;
    virtual int getLoyaltyPoints() const = 0;
    virtual bool isVIP() const = 0;

    virtual void addOrder(const Dish& d) = 0;
    virtual void setPreference(const string& pref) = 0;
    virtual void setEmail(const string& email) = 0;
    virtual void setPhone(const string& phone) = 0;
    virtual void addLoyaltyPoints(int points) = 0;
    virtual void setVIP(bool vip) = 0;
};
