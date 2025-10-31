#include "Customer.h"

Customer::Customer(const string& n, const string& p, const string& e,
    const string& ph, int points, bool vip)
    : name(n), preferences(p), email(e), phone(ph),
    loyaltyPoints(points), vipStatus(vip) {}

string Customer::getName() const { return name; }
const vector<Dish>& Customer::getOrders() const { return orders; }
string Customer::getPreferences() const { return preferences; }
string Customer::getEmail() const { return email; }
string Customer::getPhone() const { return phone; }
int Customer::getLoyaltyPoints() const { return loyaltyPoints; }
bool Customer::isVIP() const { return vipStatus; }

void Customer::addOrder(const Dish& d) { orders.push_back(d); }
void Customer::setPreference(const string& pref) { preferences = pref; }
void Customer::setEmail(const string& e) { email = e; }
void Customer::setPhone(const string& ph) { phone = ph; }
void Customer::addLoyaltyPoints(int points) { loyaltyPoints += points; }
void Customer::setVIP(bool vip) { vipStatus = vip; }
