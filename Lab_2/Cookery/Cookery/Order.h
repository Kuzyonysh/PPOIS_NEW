#pragma once
#include "IOrder.h"

class Order : public IOrder {
private:
    Customer client;
    vector<Dish> dishes;
    int orderTime;
    string status;
    string deliveryAddress;
    string paymentMethod;
    string comment;

public:
    Order(const Customer& c, int time, const string& s = "pending");

    string getStatus() const override;
    int getOrderTime() const override;
    const Customer& getClient() const override;
    const vector<Dish>& getDishes() const override;
    string getDeliveryAddress() const override;
    string getPaymentMethod() const override;
    string getComment() const override;

    void setStatus(const string& newStatus) override;
    void addOrder(const Dish& d) override;
    void setDeliveryAddress(const string& address) override;
    void setPaymentMethod(const string& method) override;
    void setComment(const string& comment) override;
    bool isReadyToServe() const override;
};
