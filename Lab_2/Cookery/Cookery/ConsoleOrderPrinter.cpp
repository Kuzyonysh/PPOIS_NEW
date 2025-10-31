#include "ConsoleOrderPrinter.h"

void ConsoleOrderPrinter::print(const IOrder& order) const {
    cout << "Customer: " << order.getClient().getName() << endl;
    cout << "Order time: " << order.getOrderTime() << " min" << endl;
    cout << "Status: " << order.getStatus() << endl;
    cout << "Delivery address: " << order.getDeliveryAddress() << endl;
    cout << "Payment method: " << order.getPaymentMethod() << endl;
    cout << "Comment: " << order.getComment() << endl;

    const auto& dishes = order.getDishes();
    if (dishes.empty()) {
        cout << "No dishes in this order." << endl;
    }
    else {
        cout << "Dishes:" << endl;
        for (const auto& d : dishes) {
            cout << " - " << d.getName() << " (" << d.getCalories() << " kcal)" << endl;
        }
    }
}
