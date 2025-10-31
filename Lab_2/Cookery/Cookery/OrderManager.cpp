#include "OrderManager.h"

double OrderManager::getTotalCalories(const IOrder& order) const {
    double total = 0;
    for (const auto& d : order.getDishes()) {
        total += d.getCalories();
    }
    return total;
}

void OrderManager::markAsServed(IOrder& order) const {
    if (order.isReadyToServe()) {
        order.setStatus("served");
        cout << "Order has been served to " << order.getClient().getName() << endl;
    }
    else {
        cout << "Order is not ready to serve yet!" << endl;
    }
}

void OrderManager::addDishToOrder(IOrder& order, const Dish& dish) const {
    order.addOrder(dish);
    cout << "Dish " << dish.getName() << " added to " << order.getClient().getName() << "'s order." << endl;
}

void OrderManager::cancelOrder(IOrder& order) const {
    order.setStatus("cancelled");
    cout << "Order for " << order.getClient().getName() << " has been cancelled." << endl;
}

void OrderManager::updateDeliveryAddress(IOrder& order, const string& address) const {
    order.setDeliveryAddress(address);
    cout << "Delivery address updated to: " << address << endl;
}

void OrderManager::updatePaymentMethod(IOrder& order, const string& method) const {
    order.setPaymentMethod(method);
    cout << "Payment method set to: " << method << endl;
}

void OrderManager::addComment(IOrder& order, const string& comment) const {
    order.setComment(comment);
    cout << "Comment added to order: " << comment << endl;
}
