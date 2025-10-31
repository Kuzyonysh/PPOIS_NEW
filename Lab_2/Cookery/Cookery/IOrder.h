#pragma once
#include <string>
#include <vector>
#include "Customer.h"
#include "Dish.h"
using namespace std;

class IOrder {
public:
    virtual ~IOrder() = default;

    virtual string getStatus() const = 0;
    virtual int getOrderTime() const = 0;
    virtual const Customer& getClient() const = 0;
    virtual const vector<Dish>& getDishes() const = 0;
    virtual string getDeliveryAddress() const = 0;
    virtual string getPaymentMethod() const = 0;
    virtual string getComment() const = 0;

    virtual void setStatus(const string& newStatus) = 0;
    virtual void addOrder(const Dish& d) = 0;
    virtual void setDeliveryAddress(const string& address) = 0;
    virtual void setPaymentMethod(const string& method) = 0;
    virtual void setComment(const string& comment) = 0;
    virtual bool isReadyToServe() const = 0;
};
