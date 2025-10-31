#include "Order.h"

Order::Order(const Customer& c, int time, const string& s)
    : client(c), orderTime(time), status(s) {}

string Order::getStatus() const { return status; }
int Order::getOrderTime() const { return orderTime; }
const Customer& Order::getClient() const { return client; }
const vector<Dish>& Order::getDishes() const { return dishes; }
string Order::getDeliveryAddress() const { return deliveryAddress; }
string Order::getPaymentMethod() const { return paymentMethod; }
string Order::getComment() const { return comment; }

void Order::setStatus(const string& newStatus) { status = newStatus; }
void Order::addOrder(const Dish& d) { dishes.push_back(d); }
void Order::setDeliveryAddress(const string& address) { deliveryAddress = address; }
void Order::setPaymentMethod(const string& method) { paymentMethod = method; }
void Order::setComment(const string& c) { comment = c; }

bool Order::isReadyToServe() const {
    return !dishes.empty() && status == "pending";
}
