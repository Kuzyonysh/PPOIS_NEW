#pragma once
#include "IOrder.h"
#include <iostream>
using namespace std;

class OrderManager {
public:
    double getTotalCalories(const IOrder& order) const;
    void markAsServed(IOrder& order) const;
    void addDishToOrder(IOrder& order, const Dish& dish) const;
    void cancelOrder(IOrder& order) const;
    void updateDeliveryAddress(IOrder& order, const string& address) const;
    void updatePaymentMethod(IOrder& order, const string& method) const;
    void addComment(IOrder& order, const string& comment) const;
};
