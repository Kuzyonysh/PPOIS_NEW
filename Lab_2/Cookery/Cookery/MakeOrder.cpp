#include "MakeOrder.h"

void ConsoleMakeOrder::makeOrder(ICustomer& customer, const Dish& dish) const {
    customer.addOrder(dish);
    cout << "Customer " << customer.getName()
        << " ordered " << dish.getName() << endl;

    customer.addLoyaltyPoints(10);
    cout << customer.getName() << " earned 10 loyalty points, total: "
        << customer.getLoyaltyPoints() << endl;
}
